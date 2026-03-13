// My approach but not optimal and chatGPT Coded

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int count = 0;

        for(int i = 0; i < words2.size(); i++) {

            int c1 = 0;
            int c2 = 0; 

            for(int j = 0; j < words1.size(); j++) {
                if(words1[j] == words2[i]) {
                    c1++;
                }
            }

            for(int j = 0; j < words2.size(); j++) {
                if(words2[j] == words2[i]) {
                    c2++;
                }
            }

            if(c1 == 1 && c2 == 1) {
                count++;
            }
        }

        return count;
    }
};









// Leetcode optimal solution

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int count = 0; 
        std::unordered_map<string_view, int> freq;

        for(auto& word : words1)
        {
            if(freq.contains(word))
            {
                freq[word]--;
            }
            else
            {
                freq[word]++;
            }

        }

        for(auto& word : words2)
        {
            if(freq.contains(word) && freq[word] == 1)
            {
                freq[word]++;
            }
            else if(freq.contains(word) && freq[word] > 1)
            {
                freq.erase(word);
            }
        }

        for(auto& [_, occurence] : freq)
        {
            if(occurence == 2)
            {
                count++;
            }
        }

        return count;
    }
};