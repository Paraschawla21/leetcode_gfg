class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 and j < 0) return true;
        if (i < 0 and j >= 0) return false;
        if (i >= 0 and j < 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] or s[i] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp);
        if (s[i] == '*') return dp[i][j] = solve(i-1, j, s, p, dp) | solve(i, j-1, s, p, dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, p, s, dp);
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (p[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[i-1] == s[j-1] or p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                if (p[i-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};