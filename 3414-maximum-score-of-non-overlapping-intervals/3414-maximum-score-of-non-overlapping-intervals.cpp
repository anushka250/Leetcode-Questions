class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;

        Node() {
            score = -1;
        }

        Node(long long s, vector<int> v) {
            score = s;
            ids = v;
        }
    };

    vector<vector<Node>> dp;
    vector<int> nxt;
    vector<vector<int>> a;

    Node solve(int i, int k) {

        if (i >= a.size() || k == 0)
            return Node(0, {});

        if (dp[i][k].score != -1)
            return dp[i][k];

        Node skip = solve(i + 1, k);

        Node takeNext = solve(nxt[i], k - 1);

        vector<int> takeIds;

        takeIds.push_back(a[i][2]);

        for (int x : takeNext.ids)
            takeIds.push_back(x);

        sort(takeIds.begin(), takeIds.end());

        Node take(a[i][3] + takeNext.score, takeIds);

        if (take.score > skip.score)
            return dp[i][k] = take;

        if (take.score < skip.score)
            return dp[i][k] = skip;

        if (take.ids < skip.ids)
            return dp[i][k] = take;

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                i,
                intervals[i][2]
            };
        }

        sort(a.begin(), a.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        nxt.resize(n);

        for (int i = 0; i < n; i++) {

            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        dp.assign(n + 1, vector<Node>(5));

        return solve(0, 4).ids;
    }
};