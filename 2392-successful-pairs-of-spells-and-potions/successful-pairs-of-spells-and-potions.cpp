class Solution {
public:
    int binarySearch(int num , vector<int>& potions,long long success)
    {
        int low = 0 ; int high = potions.size()-1;
        int ans = high+1;

        while(low <= high)
        {
            int mid = (low+high)/2;

            long long mul = (long long)potions[mid]*num;
            if(mul >= success)
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());
        int m = potions.size();

        vector<int> ans(spells.size(),0);

        for(int i = 0 ; i < spells.size() ; i++)
        {
            int lowest_idx = binarySearch(spells[i],potions,success);
            ans[i] = m - lowest_idx;
        }
        return ans;
        
    }
};