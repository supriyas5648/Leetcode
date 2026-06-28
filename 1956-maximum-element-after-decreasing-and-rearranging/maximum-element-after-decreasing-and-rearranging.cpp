class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      sort(arr.begin(),arr.end());

      arr[0] = 1;
      int maxm = 1;
      for(int i = 1 ; i < arr.size() ; i++)
      {
         if(arr[i] == arr[i-1] && arr[i] <= maxm) continue;
         
         //dusra number possible
         maxm = maxm + 1;
      }  
      return maxm; 
    }
};