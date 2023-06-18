class Solution {
public:
    long mod = 1e9+7;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1) return dp[i][j];
        long long ans = 1;
        for (int x = 0; x < 4; x++)
        {
            int newi = i + dx[x];
            int newj = j + dy[x];
            if (newi >= 0 and newi < grid.size() and newj >= 0 and newj < grid[0].size() and grid[i][j] < grid[newi][newj])
            {
                ans = (ans % mod + dfs(newi, newj, grid, dp) % mod) % mod;
            }
        }
        return dp[i][j] = (int)ans % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        long long count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count = (count % mod + dfs(i, j, grid, dp) % mod) % mod;
            }
        }
        return (int)count % mod;
    }
};