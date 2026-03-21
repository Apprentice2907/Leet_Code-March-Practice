// My approach but not optimal 

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};






// Leetcode optimmal solution

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        if(nums.size()==1) return 0; 
        int count= 0;
        for(int i =0;i<=nums.size()-2;i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]==nums[j] && ((i*j)%k==0)){
                    count++;
                }
            }
        }

        return count;
    }
};