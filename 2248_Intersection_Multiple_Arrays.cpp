// My approach but chatGPT coded

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> s(nums[0].begin(), nums[0].end());
        for (int i = 1; i < nums.size(); i++) {
            set<int> temp;
            for (int num : nums[i]) {
                if (s.count(num)) {
                    temp.insert(num);
                }
            }
            s = temp;
        }
        return vector<int>(s.begin(), s.end());
    }
};




// Leetcode optimal solution

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int>count;
        for(int i=0; i<nums.size();i++){
            for(int j=0; j<nums[i].size(); j++){
                count[nums[i][j]]++;
            }
        }
        int m = nums.size();
        vector<int>ans;
        for(auto x : count){
            if(x.second == m)ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};