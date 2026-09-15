class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        vector<char> pal(n, false);

        for (int r = 0; r < n; r++) {

            vector<char> cur(n, false);

            dp[r + 1] = dp[r];

            for (int l = r; l >= 0; l--) {

                if (s[l] == s[r] &&
                    (r - l <= 1 || pal[l + 1])) {

                    cur[l] = true;

                    if (r - l + 1 >= k) {
                        dp[r + 1] = max(
                            dp[r + 1],
                            dp[l] + 1
                        );
                    }
                }
            }

            pal.swap(cur);
        }

        return dp[n];
    }
};