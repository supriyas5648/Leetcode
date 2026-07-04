class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int i = 0 ; int j = 0;
      int ans = 0;

      while(j < nums.size())
      {
        if(nums[j] == 1) j++; //expand
        else
        {
            // we have k left
            if(k > 0) { k--;j++;} 
            else 
            {
              //k khatam 
              ans = max(ans,j-i);

             //yaha k used tha
              if(nums[i] == 0) k++;
              i++; //shrink
            }
        }
      }  
      ans = max(j-i,ans); //what if last wala
      return ans;
    }
};