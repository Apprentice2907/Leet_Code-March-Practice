// My approach but not optimal 

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
         
        for (int x : nums) {
            freq[x]++;
        }

        for (auto it : freq) {
            if (it.second % 2 != 0) {
                return false;
            }
        }

        return true;

    }
};









// Leetcode optimal solution

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n&1)return false;
        for(int i=0;i<n-1;i+=2){
            if(nums[i]!=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};