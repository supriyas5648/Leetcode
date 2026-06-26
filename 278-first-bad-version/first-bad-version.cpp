// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

       long long low = 1;
       long long high = n;
       int ans ;

       while(low <= high)
       {
         long long  mid = (high + low)/2;

         if(isBadVersion(mid))//ye hai..ab is se pehle bhi dekho
         {
           ans = mid;
           high = mid-1;
         }else
         {
            low = mid+1;
         }
       } 
       return ans;
    }
};