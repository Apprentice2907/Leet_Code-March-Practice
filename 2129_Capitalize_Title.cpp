// My approach and coded and also optimal too

class Solution {
public:
    string capitalizeTitle(string title) {
        string ans = "";
        stringstream ss(title);
        string word;

        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.size() > 2) {
                word[0] = toupper(word[0]);
            }

            if (!ans.empty()) ans += " ";
            ans += word;
        }
        return ans;
    }
};