class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> tree, lazy, sqTree;

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;

        sqTree[node] = (sqTree[node]
            + 2 * v % MOD * tree[node] % MOD
            + v * v % MOD * len % MOD) % MOD;

        tree[node] = (tree[node] + v * len) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
        sqTree[node] = (sqTree[node * 2] + sqTree[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n, 0);
        sqTree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + sqTree[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};