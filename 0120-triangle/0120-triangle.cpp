class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &a, vector<vector<int>> &dp)
    {
        if (i == n - 1) return a[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int down = a[i][j] + solve(i+1, j, n, a, dp);
        int diagonal = a[i][j] + solve(i+1, j+1, n, a, dp);
        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};