class Solution {
public:
    int dp[100][100][201];

    bool check(vector<vector<char>>& grid, int i, int j, int balance) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][balance] = (balance == 0);

        bool down = check(grid, i + 1, j, balance);
        bool right = check(grid, i, j + 1, balance);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));

        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        return check(grid, 0, 0, 0);
    }
};