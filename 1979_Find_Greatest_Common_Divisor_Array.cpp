// My logicc combining other solutions

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int minm = nums[0];
        int maxm = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minm)
                minm = nums[i];
            if (nums[i] > maxm)
                maxm = nums[i];
        }

        return gcd(minm, maxm);
    }
};







// My solutiob but chatGPT coded and optimal solution too

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minm = *min_element(nums.begin(), nums.end());
        int maxm = *max_element(nums.begin(), nums.end());
        return gcd(minm, maxm);
    }
};