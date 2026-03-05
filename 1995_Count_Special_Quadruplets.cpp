// SImple brute force 

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        if(nums[i] + nums[j] + nums[k] == nums[l]){
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};









// Leetcode optimal solution

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // nums[a] + nums[b] + nums[c] == nums[d]
        // nums[a] + nums[b] == nums[d] - nums[c]
        // a < b < c < d
        int n = nums.size();
        int res = 0;
        std::vector<int> m(201, 0);
        for (int a = 0; a < n; ++a) {
            // std::vector<int> m(201, 0);
            std::fill(m.begin(), m.end(), 0);
            for (int b = n - 1; b > a; --b) {
                int c = b + 1;
                for (int d = c + 1; d < n; ++d) {
                    if (nums[d] - nums[c] >= 0) {
                        ++m[nums[d] - nums[c]];
                    }
                }
                res += m[nums[a] + nums[b]];
                // auto iter = m.find(nums[a] + nums[b]);
                // if (iter != m.end()) {
                //     res += iter->second;
                // }
            }
        }

        return res;
    }
};