class Solution {
public:
    bool solve(int i, int j, int k, int n, int m, int s, vector<vector<vector<int>>> &dp, string &s1, string &s2, string &s3)
    {
        if (i >= n and j >= m and k >= s) return true;
        if (k >= s) return false;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        bool flag1 = false;
        if (s1[i] == s3[k]) flag1 = solve(i+1, j, k+1, n, m, s, dp, s1, s2, s3);
        bool flag2 = false;
        if (s2[j] == s3[k]) flag2 = solve(i, j+1, k+1, n, m, s, dp, s1, s2, s3);
        return dp[i][j][k] = flag1 or flag2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int s = s3.size();
        if (n + m != s) return false;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(s+1, -1)));
        return solve(0, 0, 0, n, m, s, dp, s1, s2, s3);
    }
};