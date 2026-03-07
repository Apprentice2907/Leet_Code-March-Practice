// My approach and optimal solution too

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxd = -1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i]){  
                    int temp = nums[j] - nums[i];
                    if(temp > maxd){
                        maxd = temp;
                    }
                }
            }
        }
        return maxd;
    }
};