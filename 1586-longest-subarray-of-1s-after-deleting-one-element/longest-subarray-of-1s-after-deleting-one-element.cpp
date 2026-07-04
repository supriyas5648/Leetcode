class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int zeros = 0;
        int ans = 0;
        int k = 1;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[i] == 0)
                    zeros--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans-1; //coz 1 elem we replaced 0->1 ..so reduced it
    }
};  