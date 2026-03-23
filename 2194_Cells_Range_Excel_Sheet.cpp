//  my approach but chatGPT help but optimal too

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char startc = s[0];
        char endc = s[3];
        int startr = s[1] - '0';
        int endr = s[4] - '0';

        vector<string> ans;

        if (startr == endr) {
            for (char c = startc; c <= endc; c++) {
                ans.push_back(string(1, c) + to_string(startr));
            }
        }
        else {
            for (char c = startc; c <= endc; c++) {
                for (int r = startr; r <= endr; r++) {
                    ans.push_back(string(1, c) + to_string(r));
                }
            }
        }
        return ans;
    }
};