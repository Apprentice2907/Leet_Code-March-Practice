// My logic but chatGPT coded and not optimmal

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;

        // Separate elements
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }

        // Sort
        sort(even.begin(), even.end()); // ascending
        sort(odd.begin(), odd.end(), greater<int>()); // descending

        // Place back
        int e = 0, o = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                nums[i] = even[e++];
            else
                nums[i] = odd[o++];
        }

        return nums;
    }
};







// Leetcode optimal solution same

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
     int n=nums.size();
     vector<int>even;
     vector<int>odd;
     for(int i=0;i<n;i++){
        if(i%2==0)even.push_back(nums[i]);
        else odd.push_back(nums[i]);
     }
     sort(even.begin(),even.end());
     sort(odd.begin(),odd.end(),greater<int>());
     int i=0,j=0;
     for(int k=0;k<n;k++){
        if(k%2==0)nums[k]=even[i++];
        else nums[k]=odd[j++];
     }

     return nums;
    }
};

