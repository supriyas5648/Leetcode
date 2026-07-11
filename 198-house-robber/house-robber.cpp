class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);

        for(int i =0 ; i < nums.size() ; i++)
        {
            int skip = (i-1 < 0)? 0 : dp[i-1];
            int include = ((i-2 < 0)? 0 : dp[i-2])+ nums[i];
            dp[i] = max(skip,include);
        }

        return dp[nums.size()-1];
    }
};