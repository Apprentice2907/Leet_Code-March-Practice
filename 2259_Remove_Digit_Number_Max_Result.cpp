// My approach and little bit chatGPT too

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();

        for (int i = 0; i < n - 1; i++) {
            if (number[i] == digit && number[i] < number[i + 1]) {
                return number.substr(0, i) + number.substr(i + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (number[i] == digit) {
                return number.substr(0, i) + number.substr(i + 1);
            }
        }

        return "";
    }
};