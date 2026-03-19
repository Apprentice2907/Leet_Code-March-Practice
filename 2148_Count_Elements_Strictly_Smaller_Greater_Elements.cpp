// My approach and coded and optimal too

class Solution {
public:
    int countElements(vector<int>& nums) {
        int count=0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        for(auto num:nums){
            if(num<maxVal && num>minVal) count=count+1;
        }
        return count;
    }
};