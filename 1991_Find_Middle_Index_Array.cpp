// My logic but chatGPT helped in coding and also optimal solution too 

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        for(int x : nums){
            rightSum += x;
        }

        for(int i = 0; i < nums.size(); i++){
            rightSum -= nums[i];   

            if(leftSum == rightSum){
                return i;
            }

            leftSum += nums[i]; 
        }

        return -1;
    }
};