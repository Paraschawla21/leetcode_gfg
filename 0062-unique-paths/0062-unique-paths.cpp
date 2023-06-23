class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m-1 and j == n-1) return 1;
        if (i >= m or j >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solve(0, 0, m, n, dp);
        
        // google's interview solution
        int N = n + m - 2;
        int r = m - 1;
        double ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * (N - r + i) / i;
        }
        return ans;
    }
};