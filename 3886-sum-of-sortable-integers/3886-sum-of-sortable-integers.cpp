
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;
                int mn = nums[start];
                int mx = nums[start];

                // Check whether this block can be sorted by rotation.
                for (int j = 0; j < k; j++) {
                    int curr = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    if (curr > next) {
                        descents++;
                    }

                    mn = min(mn, curr);
                    mx = max(mx, curr);
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                // The sorted blocks must join in non-decreasing order.
                if (start > 0) {
                    int prevMax = *max_element(
                        nums.begin() + start - k,
                        nums.begin() + start
                    );

                    if (prevMax > mn) {
                        valid = false;
                    }
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
