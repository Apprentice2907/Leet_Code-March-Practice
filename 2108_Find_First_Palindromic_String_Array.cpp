// My approach but not optimal 
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string w : words) {
            string rev = "";
            
            for(int i = w.length() - 1; i >= 0; i--) {
                rev += w[i];
            }
            
            if(w == rev) {
                return w;
            }
        }
        
        return "";
    }
};







// Leetcode optimal solution

class Solution {
public:
    bool check(string& word){
        int i = 0, j = word.length()-1;
        while(i<j){
            if(word[i]!=word[j]) return false;
            i++; j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto& word : words){
            if(check(word)) return word;
        }
        return "";
    }
};