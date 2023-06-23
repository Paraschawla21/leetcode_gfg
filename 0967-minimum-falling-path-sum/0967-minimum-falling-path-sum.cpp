class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 or j >= n) return 1e7;
        if (i == 0) return matrix[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int up = matrix[i][j] + solve(i-1, j, n, matrix, dp);
        int leftDiagonal = matrix[i][j] + solve(i-1, j-1, n, matrix, dp);
        int rightDiagonal = matrix[i][j] + solve(i-1, j+1, n, matrix, dp);
        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e7));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiagonal = INT_MAX;
                int rightDiagonal = INT_MAX;
                if (j > 0) leftDiagonal = matrix[i][j] + dp[i-1][j-1];
                if (j < n-1) rightDiagonal = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};