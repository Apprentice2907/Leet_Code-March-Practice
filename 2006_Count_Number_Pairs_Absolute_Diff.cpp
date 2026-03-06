// My approach and near to optimal solution

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(abs(nums[i] - nums[j]) == k){
                    count++;
                }
            }
        }

        return count;
    }
};





// Leetcode optimal solution

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        long long count=0;
        int left=0;
        while(left<nums.size()){
            for(int i=left+1;i<nums.size();i++){
                if(abs(nums[i]-nums[left])==k){
                    count++;

                }
            }
            left++;
        }
        return count;
    }
};