class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // Check rotations that sort the array
        for (int k = 0; k < n; k++) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (nums[(i + k) % n] != i) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = min(ans, min(k, n - k + 2));
            }
        }

        // Check reversed rotations
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        for (int k = 0; k < n; k++) {
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (rev[(i + k) % n] != i) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = min(ans, min(k + 1, n - k + 1));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};