class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int st, int k, int en, vector<int>& a, vector<vector<int>>& dp)
    {
        if (k < 0) return 0;
        if (dp[st][k] != -1) return dp[st][k];
        int ans = 0;
        if (st == en) ans++;
        for (int i = 0; i < a.size(); i++)
        {
            if ((i != st) and (abs(a[i] - a[st]) <= k))
            {
                ans = (ans + solve(i, k - abs(a[i] - a[st]), en, a, dp)) % MOD;
            }
        }
        return dp[st][k] = ans % MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return solve(start, fuel, finish, locations, dp);
    }
};