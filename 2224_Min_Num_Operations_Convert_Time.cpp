// My apporach but chatGPT coded

class Solution {
public:
    int convertTime(string current, string correct) {
        
        int ch = (current[0]-'0')*10 + (current[1]-'0');
        int cm = (current[3]-'0')*10 + (current[4]-'0');
        int curr = ch*60 + cm;

        int th = (correct[0]-'0')*10 + (correct[1]-'0');
        int tm = (correct[3]-'0')*10 + (correct[4]-'0');
        int target = th*60 + tm;

        int count = 0;

        while(curr < target) {
            curr = curr + 1;
            count = count + 1;
        }

        return count;
    }
};







// Optimal solution

class Solution {
public:
    int convertTime(string current, string correct) {
        int curr = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int corr = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));

        int diff = corr - curr;
        int count = 0;

        int steps[] = {60, 15, 5, 1};

        for (int i = 0; i < 4; i++) {
            count += diff / steps[i];
            diff %= steps[i];
        }

        return count;
    }
};