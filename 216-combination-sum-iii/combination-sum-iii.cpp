class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int n,int k ,int i , int sum,vector<int>& temp)
    {
        if( i == 10 || sum >= n || temp.size() == k)
        {
            if( temp.size() == k && sum == n) ans.push_back(temp);
            return;
        } 

        //include
        temp.push_back(i);
        backtrack(n,k ,i+1,sum + i ,temp);

        //exclude
        temp.pop_back();
        backtrack(n,k,i+1,sum ,temp);
         
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        backtrack(n,k,1,0,temp);
        return ans;
    }
};