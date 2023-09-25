class Solution {
public:
    double solve(int i, int j, int n, vector<vector<double>> &dp)
    {
        if (i < 0 or j < 0 or i < j) return 0.0;
        if (i == 0 and j == 0) return (double)n;
        if (dp[i][j] != -1) return dp[i][j];
        double leftUp = (solve(i-1, j-1, n, dp) - 1) / 2.0;
        double rightUp = (solve(i-1, j, n, dp) - 1) / 2.0;
        if (leftUp < 0) leftUp = 0.0;
        if (rightUp < 0) rightUp = 0.0;
        return dp[i][j] = leftUp + rightUp;
    }
    double champagneTower(int poured, int r, int c) {
        vector<vector<double>> dp(r+1, vector<double>(c+1, -1));
        return min(1.0, solve(r, c, poured, dp));
    }
};