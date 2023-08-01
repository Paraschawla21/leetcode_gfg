class Solution {
public:
    int solve(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i >= n and j >= m) return 0;
        if (i >= n) return s2[j] + solve(i, j+1, n, m, s1, s2, dp);
        if (j >= m) return s1[i] + solve(i+1, j, n, m, s1, s2, dp);
        if (s1[i] == s2[j]) return solve(i+1, j+1, n, m, s1, s2, dp);
        if (dp[i][j] != -1) return dp[i][j];
        int delete_i = s1[i] + solve(i+1, j, n, m, s1, s2, dp);
        int delete_j = s2[j] + solve(i, j+1, n, m, s1, s2, dp);
        return dp[i][j] = min(delete_i, delete_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, s1, s2, dp);
    }
};