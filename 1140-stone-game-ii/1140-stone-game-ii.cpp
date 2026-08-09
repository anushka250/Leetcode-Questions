class Solution {
public:
    int dp[101][101];
    vector<int> suffix;

    int solve(int i, int M) {
        int n = suffix.size() - 1;

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = solve(i + X, max(M, X));

            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
         int n = piles.size();

        memset(dp, -1, sizeof(dp));

        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1);
    
    }
};