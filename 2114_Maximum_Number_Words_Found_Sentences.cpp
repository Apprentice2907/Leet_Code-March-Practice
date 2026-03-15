// My approach but chatGPT coded but optimal

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for(string s : sentences) {
            int count = 1; 

            for(char c : s) {
                if(c == ' ')
                    count++;
            }

            if(count > maxWords)
                maxWords = count;
        }

        return maxWords;
    }
};