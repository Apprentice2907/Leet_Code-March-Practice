class Solution {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (!isAnagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};