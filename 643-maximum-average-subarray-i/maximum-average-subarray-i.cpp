class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double ans = INT_MIN;
      int i = 0 ; int j = 0;
      int sum = 0;

      while( j < nums.size())
      {
        //make window
        if(j < k)
        {
          while(j < k)
          {
          sum+= nums[j];
          j++;
          }
        }else
        {
            sum -= nums[i++];
            sum += nums[j++];
        }

        //avg
        ans = max(ans,(double)sum/k);
      }
      return ans;
    }
};