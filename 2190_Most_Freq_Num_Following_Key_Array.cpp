// My approach adn optimal too just little bit chatGPT help

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> count;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == key){
                count[nums[i + 1]]++;
            }
        }

        int maxc = 0;
        int maxf = 0;

        for(auto &p : count){
            int val = p.first;
            int freq = p.second;

            if(freq > maxc || (freq == maxc && val > maxf)){
                maxc = freq;
                maxf = val;
            }
        }

        return maxf;
    }
};