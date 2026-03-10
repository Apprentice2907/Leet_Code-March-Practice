// My logic but not worked

class Solution {
public:
    int countValidWords(string sentence) {
        string w;
        stringstream s(sentence);
        int ans = 0;

        while (s >> w) {
            bool ok = true;

            for (char c : w) {
                if (!isalpha(c)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;
        }

        return ans;
    }
};







// ChatGPT solution but not optimal 

class Solution {
public:
    int countValidWords(string sentence) {
        string w;
        stringstream ss(sentence);
        int ans = 0;

        while (ss >> w) {
            int hy = 0, p = 0;
            bool ok = true;

            for (int i = 0; i < w.size(); i++) {

                if (isdigit(w[i])) ok = false;

                if (w[i] == '-') {
                    hy++;
                    if (hy > 1 || i == 0 || i == w.size()-1 || 
                        !islower(w[i-1]) || !islower(w[i+1]))
                        ok = false;
                }

                if (w[i] == '!' || w[i] == '.' || w[i] == ',') {
                    p++;
                    if (p > 1 || i != w.size()-1)
                        ok = false;
                }
            }

            if (ok) ans++;
        }

        return ans;
    }
};









// Leetcode optimal solution

class Solution {
public:
    bool isValid(string word) {
        if (word.size() == 0)
            return false;

        int hc = 0, pc = 0;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (isdigit(c))
                return false;

            if (c == '-') {
                hc++;
                if (hc > 1)
                    return false;
                if (i == 0 || i == word.size() - 1)
                    return false;
                if (!isalpha(word[i - 1]) || !isalpha(word[i + 1]))
                    return false;
            }

            if (c == '.' || c == ',' || c == '!') {
                pc++;
                if (pc > 1 || i != word.size() - 1)
                    return false;
            }
        }

        return true;
    }
    int countValidWords(string sentence) {
        int cnt = 0;
        int i = 0;
        int n = sentence.size();

        while (i < n) {
            while (i < n && sentence[i] == ' ')
                i++;
            string word = "";
            while (i < n && sentence[i] != ' ') {
                word += sentence[i];
                i++;
            }

            if (isValid(word))
                cnt++;
        }
        return cnt;
    }
};