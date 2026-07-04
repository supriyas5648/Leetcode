class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //find total sum
        int total = 0;
        for(int num : nums)
        {
          total += num;
        } 

        int left_sum = 0;
        for(int i =0 ; i < nums.size() ; i++)
        {
          int right_sum = total - (left_sum+nums[i]);

          if(left_sum == right_sum) return i;
          
          left_sum += nums[i];
        }

        return -1;
    }
};