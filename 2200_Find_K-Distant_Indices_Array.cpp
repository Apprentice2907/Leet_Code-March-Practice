// ChatGPT coded but not optimal

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        vector<bool> visited(n, false); // to avoid duplicates

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);

                for (int i = start; i <= end; i++) {
                    if (!visited[i]) {
                        result.push_back(i);
                        visited[i] = true;
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};









// Leetcode optimal solution

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;  
        int n = nums.size();
        for(int j=0; j<n; j++) {
            if(nums[j]==key) {
                int l = max(r, j-k);
                r = min(n-1, j+k) + 1;
                for(int i=l; i<r; ++i) res.push_back(i);
            }
        }
        return res;
    }
};