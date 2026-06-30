class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     if( nums.size() < 3) return false; 

     int i = INT_MAX;
     int j = INT_MAX;

     for(int num : nums)
     {
        if(num <= i)
        {
            i = num; //i se chota val
        }else if( num <= j)
        {
            //i se bada and j se chota
            j = num;
        }else
        {
            //i se bada.....j se bada
            return true;
        }
     }
      return false;
    }
};