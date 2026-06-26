class Solution {
public:

    long long TimeTaken(int k,vector<int>& piles )
    {
      long long time_req = 0;
      for(int pile : piles)
      {
        time_req +=(pile+k-1)/k;
      }

      return time_req;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

       sort(piles.begin(), piles.end());
       long long low = 1;
       long long high = piles[piles.size()-1];
       long long ans = high;

       while(low <= high)
       {
         long long mid = low + (high-low)/2;

         //check for this mid val
         if(TimeTaken(mid,piles) <= (long long)h)
         {
           ans = mid;
           high = mid-1;
         }else
         {
            low = mid+1;
         }
       }
       return (int)ans;
    }
};