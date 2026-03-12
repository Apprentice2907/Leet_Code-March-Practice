// My approach optimal solution too but chatGPT coded 

class Solution {
public:

    bool checkfreq(string &s1, string &s2, int index, vector<int> &f1, vector<int> &f2) {

        if(index < s1.length()) {
            f1[s1[index] - 'a']++;
            f2[s2[index] - 'a']++;

            return checkfreq(s1, s2, index + 1, f1, f2);
        }
        else {
            for(int i = 0; i < 26; i++) {
                if(abs(f1[i] - f2[i]) > 3)
                    return false;
            }
            return true;
        }
    }

    bool checkAlmostEquivalent(string word1, string word2) {

        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        return checkfreq(word1, word2, 0, f1, f2);
    }
};