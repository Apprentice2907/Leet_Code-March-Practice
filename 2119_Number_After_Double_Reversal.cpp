// My approach and my coded and optimal too

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num >= 0 && num <= 9) return true;
        if(num%10==0) return false;
        return true;
    }
};