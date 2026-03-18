// My approach but not optimal 

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0;
        sort(cost.rbegin(), cost.rend());

        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 == 2) continue;  
            sum += cost[i];
        }
        return sum;
    }
};







// Leetcode optimal solution

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int ans=0;
        if(n%3==0){
            int i=n-1;
            while(i>=0){
               ans+=cost[i]+cost[i-1];
                i-=3;
            }
        }
        else if(n%3==2){
           int i=n-1;
            while(i>=2){
                ans+=cost[i]+cost[i-1];
                i-=3;
            }
            while(i>=0){
                ans+=cost[i];
                i--;
            }
        }
        else{
           int i=n-1;
            while(i>=1){
                ans+=cost[i]+cost[i-1];
                i-=3;
            }
            while(i>=0){
                ans+=cost[i--];
            }
        }
        return ans;
    }
};