// My logic but didnt work 

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;     
                max1 = nums[i];  
            }
            else if (nums[i] > max2 && nums[i] != max1) {
                max2 = nums[i];   
            }
        }

        return max1 - max2;
    }
};







// My optimized code

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        
        return ans;
    }
};








// Leetcode optimal solution

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int min_diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i + k -1<nums.size();i++){
            int l=nums[i];
            int r=nums[i + k -1];
            int diff=r-l;
            min_diff=min(min_diff,diff);
        }
        return min_diff;
    }
};