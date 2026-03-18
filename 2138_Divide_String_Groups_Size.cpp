// My approach and coded but little bit helped and optimal too 

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        for(int i = 0; i < s.size(); i += k) {
            string res = s.substr(i, k);
            
            if(res.size() < k) {
                res += string(k - res.size(), fill);
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};