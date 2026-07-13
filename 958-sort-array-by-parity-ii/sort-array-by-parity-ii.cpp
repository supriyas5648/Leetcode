class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       int odd_idx = 1;
       int even_idx = 0;

       vector<int> ans(nums.size());

       for(int num : nums)
       {
         if(num%2 == 0)
         {
            ans[even_idx] = num;
            even_idx += 2;
         }else
         {
            ans[odd_idx] = num;
            odd_idx += 2;
         }
       } 

       return ans;
    }
};