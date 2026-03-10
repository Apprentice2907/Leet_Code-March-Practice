// My logic but chatGPT coded and not optimal 

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;

        for(string s : arr) {
            freq[s]++;
        }

        for(string s : arr) {
            if(freq[s] == 1) {
                k--;
                if(k == 0) return s;
            }
        }

        return "";
    }
};









// Leetcode optimal solution

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        int count = 1;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]==1)
            {
                if(count==k)
                {
                    return arr[i];
                }
                count++;
            }
        }
        return "";
    }
};