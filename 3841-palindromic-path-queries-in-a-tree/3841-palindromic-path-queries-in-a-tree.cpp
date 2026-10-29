class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n), parent(n);
        int timer = 0;

        vector<tuple<int, int, int>> st;
        st.push_back({0, -1, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();

            if (state == 0) {
                parent[u] = (p == -1 ? u : p);
                tin[u] = timer++;

                st.back() = {u, p, 1};

                for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
                    int v = adj[u][i];
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    a = up[j][a];

            if (a == b) return a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }

            return parent[a];
        };

        // Fenwick tree for XOR range updates
        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n + 1; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            add(r, val);  // exclusive endpoint
        };

        auto pointQuery = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        vector<int> mask(n);

        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask[u]);
        }

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                if (delta != 0) {
                    rangeUpdate(tin[u], tout[u], delta);
                    mask[u] = newMask;
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pathMask = pointQuery(tin[u])
                             ^ pointQuery(tin[v])
                             ^ mask[w];

                answer.push_back(
                    __builtin_popcount((unsigned int)pathMask) <= 1
                );
            }
        }

        return answer;
    }
};