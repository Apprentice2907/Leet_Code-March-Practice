// Brute force approach

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count=0;
        for(auto str:operations){
            if(str=="--X") count =count-1;
            if(str=="X--") count =count-1;
            if(str=="++X") count =count+1;
            if(str=="X++") count =count+1;
        }
        return count;
    }
};







// Optimal solution

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int x=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="++X" || operations[i]=="X++")
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        return x;
    }
};