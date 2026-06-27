class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[start, cnt] : freq) {

            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len++;
                if (x > LLONG_MAX / x) break;   // overflow protection
                x *= x;
            }

            if (freq.count(x) && freq[x] == 1)
                ans = max(ans, 2 * len + 1);
            else
                ans = max(ans, max(1, 2 * len - 1));
        }

        return ans;
    }
};