class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX = 2048;
        vector<vector<bool>> dp(4, vector<bool>(MAX, false));
        dp[0][0] = true;

        for (int x : nums) {
            for (int cnt = 2; cnt >= 0; cnt--) {
                for (int val = 0; val < MAX; val++) {
                    if (dp[cnt][val]) {
                        dp[cnt + 1][val ^ x] = true;
                    }
                }
            }
        }
        for (int x : nums)
            dp[3][x] = true;

        int ans = 0;
        for (bool x : dp[3])
            ans += x;

        return ans;
    }
};