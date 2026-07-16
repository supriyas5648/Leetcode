class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

       vector<int> left;
       vector<int> right(nums.size(),1);

       //left 
       left.push_back(1); //0th idx
       for(int i = 1 ; i < nums.size() ; i++)
       {
         left.push_back(nums[i-1]*left[i-1]); 
       }  

       //right
       for(int i = nums.size()-2 ; i >= 0 ; i--)
       {
        right[i] = nums[i+1]*right[i+1];
       }

       //multily for each
       vector<int> ans;
       for(int i = 0 ; i < nums.size() ; i++)
       {
        ans.push_back(left[i]*right[i]);
       }

      return ans;
    }
};