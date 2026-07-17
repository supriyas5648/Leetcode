class Solution {
public:
    int findPivot(vector<int>& nums)
    {
      int low = 0 ; int high = nums.size()-1;
      int n = nums.size();

      while(low <= high)
      {
        int mid = low + (high-low)/2;

        if(mid > 0 && nums[mid-1] > nums[mid]) return mid;
        else if(nums[mid] < nums[n-1]) high = mid-1;
        else low = mid+1;
      }

      return 0;
    }
 
    int BS(vector<int>& arr, int target,int start,int end)
    {
        int low = start ; int high = end;

        while(low <= high)
        {
            int mid = low +(high-low)/2;

            if(arr[mid] == target ) return mid;
            else if(arr[mid] < target) low = mid+1;
            else high = mid-1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {

       int pivot = findPivot(nums);
       int start = 0 ; int end = nums.size()-1; //default pivot is 0

       if(nums[nums.size()-1] >= target) //2nd half
       {
        start = pivot;
       }else end = pivot-1; // 1st half

       int ans = BS(nums,target,start,end);
       return ans;
    }
};