// My approahc but chatGPT coded

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s; 

        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {

                    if(i != j && j != k && i != k) {

                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];

                        if(a != 0 && c % 2 == 0) {
                            int num = a*100 + b*10 + c;
                            s.insert(num);
                        }
                    }
                }
            }
        }

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};








// Leetcode optimal solution 

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(100, 0);
        for (int x : digits) freq[x]++;
        vector<int> result;
        for (int i = 100; i<=998; i=i+2){
            int d1 = i%10;
            int d2 = (i/10)%10;
            int d3 = i/100;

            freq[d1]--;
            freq[d2]--;
            freq[d3]--;

            if (freq[d1]>=0 && freq[d2]>=0 && freq[d3]>=0) result.push_back(i);

            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }
        return result;
    }
};