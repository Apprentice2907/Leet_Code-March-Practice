// My approach but not optimal and chatGPT coded

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> v1, v2;
        
        for(auto x : s1){
            if(s2.find(x) == s2.end()){
                v1.push_back(x);
            }
        }
        
        for(auto x : s2){
            if(s1.find(x) == s1.end()){
                v2.push_back(x);
            }
        }
        
        return {v1, v2};
    }
};







// Leetcode optimal solution

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int l = 0, r = 0;
        while(l < nums1.size() || r < nums2.size()) {
            if(l < nums1.size() && r < nums2.size()) {
                if(nums1[l] != nums2[r]) {
                    if(nums1[l] < nums2[r]) {
                        ans[0].push_back(nums1[l++]);
                    } else {
                        ans[1].push_back(nums2[r++]);
                    }
                } else {
                    ++l; ++r;
                }
            } else {
                if(l < nums1.size()) {
                    ans[0].push_back(nums1[l++]);
                } else {
                    ans[1].push_back(nums2[r++]);
                }
            }
        }
        return ans;
    }
};