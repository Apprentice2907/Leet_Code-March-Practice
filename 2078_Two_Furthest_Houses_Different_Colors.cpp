// My logic but not optimal solution

class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int ans = 0;

        for(int i = 0; i < colors.size(); i++){
            for(int j = colors.size() - 1; j >= 0; j--){

                if(colors[i] != colors[j]){
                    ans = max(ans, abs(i - j));
                }
            }
        }

        return ans;
    }
};





// Leetcode optimal solution

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(colors[i] != colors[0])
                ans = max(ans, i);

            if(colors[i] != colors[n-1])
                ans = max(ans, n-1-i);
        }

        return ans;
    }
};