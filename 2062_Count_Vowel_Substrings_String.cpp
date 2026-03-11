// My logic but chatGPT coded and not optimal

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        int count = 0;
        string vowels = "aeiou";

        for (int i = 0; i < n; i++) {
            set<char> seen;

            for (int j = i; j < n; j++) {

                if (vowels.find(word[j]) == string::npos)
                    break;

                seen.insert(word[j]);

                if (seen.size() == 5)
                    count++;
            }
        }

        return count;
    }
};









// Leetcode optimal solution

class Solution {
public:
    int countVowelSubstrings(const string &word) {
        int res = 0;
        unordered_map<char, int> freq;
        int counter = 0, running = 0;

        int left = 0, right = 0;
        while (right < word.size()) {
            if (isVowel(word[right])) {
                if (freq[word[right]] == 0) ++counter;
                ++freq[word[right]];
            } else {
                freq.clear();
                counter = 0;
                ++right;
                running = 0;
                left = right;
                continue;
            }

            while (counter == 5) {
                if (isVowel(word[left])) {
                    --freq[word[left]];
                    if (freq[word[left]] == 0) --counter;
                    ++running;
                }
                ++left;
            }

            if (isVowel(word[right])) res += running;
            ++right;
        }

        return res;
    }

private:
    bool isVowel(const char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};