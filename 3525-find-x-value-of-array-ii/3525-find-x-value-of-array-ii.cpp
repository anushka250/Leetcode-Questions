class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };
    int n, k;
    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;
            tree[p].prod = x;
            tree[p].cnt[x] = 1;
            return;
        }

        int mid = (l + r) >> 1;

        build(p << 1, l, mid, nums);
        build(p << 1 | 1, mid + 1, r, nums);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    void update(int p, int l, int r, int pos, int value) {
        if (l == r) {
            int x = value % k;

            tree[p].prod = x;

            for (int i = 0; i < k; i++)
                tree[p].cnt[i] = 0;

            tree[p].cnt[x] = 1;
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(p << 1, l, mid, pos, value);
        else
            update(p << 1 | 1, mid + 1, r, pos, value);

        tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
    }

    void query(
        int p,
        int l,
        int r,
        int ql,
        int qr,
        Node &leftRes,
        Node &rightRes,
        bool &hasLeft,
        bool &hasRight
    ) {
        if (ql <= l && r <= qr) {
            if (!hasLeft) {
                leftRes = tree[p];
                hasLeft = true;
            } else {
                rightRes = tree[p];
                hasRight = true;
            }
            return;
        }

        int mid = (l + r) >> 1;

        if (ql <= mid)
            query(p << 1, l, mid, ql, qr,
                  leftRes, rightRes, hasLeft, hasRight);

        if (qr > mid)
            query(p << 1 | 1, mid + 1, r, ql, qr,
                  leftRes, rightRes, hasLeft, hasRight);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = K;

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            vector<int> nodes;

            int l = start + n;
            int r = n + n - 1;

            Node result;
            bool found = false;

            function<void(int,int,int)> get = [&](int p, int L, int R) {
                if (start <= L && R < n) {
                    if (!found) {
                        result = tree[p];
                        found = true;
                    } else {
                        result = merge(result, tree[p]);
                    }
                    return;
                }

                int mid = (L + R) >> 1;

                if (start <= mid)
                    get(p << 1, L, mid);

                if (mid + 1 < n)
                    get(p << 1 | 1, mid + 1, R);
            };

            get(1, 0, n - 1);

            ans.push_back(result.cnt[x]);
        }

        return ans;
    }
};