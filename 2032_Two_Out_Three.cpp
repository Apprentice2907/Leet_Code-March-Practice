// My approach but not optimal

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        
        vector<int> ans;

        for(int i = 0; i <= 100; i++){
            int count = 0;
            
            if(s1.count(i)) count++;
            if(s2.count(i)) count++;
            if(s3.count(i)) count++;
            
            if(count >= 2){
                ans.push_back(i);
            }
        }

        return ans;
    }
};







// Leetcode optimal solution

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            int a=nums1[i];
            if(std::find(nums2.begin(),nums2.end(),a)!=nums2.end()){
                if(std::find(result.begin(),result.end(),a)!=result.end()){
                    
                }
                else{
                    result.push_back(a);
                }
            }
            else if(std::find(nums3.begin(),nums3.end(),a)!=nums3.end()){
                if(std::find(result.begin(),result.end(),a)!=result.end()){
                    
                }
                else{
                    result.push_back(a);
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            int b=nums2[i];
            if(std::find(nums3.begin(),nums3.end(),b)!=nums3.end()){
                if(std::find(result.begin(),result.end(),b)!=result.end()){
                    
                }
                else{
                    result.push_back(b);
                }
            }
        }
        return result;
        
    }
};