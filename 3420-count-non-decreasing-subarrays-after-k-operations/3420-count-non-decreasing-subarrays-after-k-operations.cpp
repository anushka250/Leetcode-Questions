class Solution {
public:
    using ll = long long;

    int n;
    vector<int> nums;
    vector<ll> pref;
    vector<vector<int>> up;
    vector<vector<ll>> costJump;

    // Sum of prefix maximums in [l, r]
    ll getMaxSum(int l, int r) {
        ll res = 0;
        int p = l;

        for (int j = up.size() - 1; j >= 0; j--) {
            int nxt = up[j][p];

            if (nxt <= r) {
                res += costJump[j][p];
                p = nxt;
            }
        }

        // Last maximum contributes until r
        res += 1LL * nums[p] * (r - p + 1);

        return res;
    }

    // Cost to make nums[l...r] non-decreasing
    ll getCost(int l, int r) {
        ll maxSum = getMaxSum(l, r);
        ll sum = pref[r + 1] - pref[l];

        return maxSum - sum;
    }

    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        this->nums = nums;
        n = nums.size();

        // Prefix sum
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // next greater element
        vector<int> nxt(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nxt[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n + 1, n));
        costJump.assign(LOG, vector<ll>(n + 1, 0));

        // One jump:
        // nums[i] is the maximum from i to nxt[i]-1
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            costJump[0][i] =
                1LL * nums[i] * (nxt[i] - i);
        }

        up[0][n] = n;

        // Binary lifting
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];

                costJump[j][i] =
                    costJump[j - 1][i] +
                    costJump[j - 1][mid];
            }
            up[j][n] = n;
            costJump[j][n] = 0;
        }

        long long ans = 0;

        // Fix right endpoint
        for (int r = 0; r < n; r++) {

            // Find smallest l such that cost(l,r) <= k
            int lo = 0, hi = r;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (getCost(mid, r) <= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            // All l in [lo ... r] are valid
            ans += r - lo + 1;
        }

        return ans;
    }
};