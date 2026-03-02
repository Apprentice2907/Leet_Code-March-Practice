// My logic and optimal too

class Solution {
public:
    int minTimeToType(string word) {
        char curr = 'a';
        int time = 0;
        for (char ch : word) {
            int diff = abs(ch - curr);
            int move = min(diff, 26 - diff);
            time =time+ move;  
            time =time+ 1;    
            curr = ch;
        }
        return time;
    }
};