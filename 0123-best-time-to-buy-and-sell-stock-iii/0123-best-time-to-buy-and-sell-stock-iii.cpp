class Solution {
public:
    long solve(int i, int buy, int cap, int n, vector<int> &a, vector<vector<vector<long>>> &dp)
    {
        if (cap == 0 or i == n) return 0;
        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];
        long profit = 0;
        if (buy) profit = max(-a[i] + solve(i+1, 0, cap, n, a, dp), solve(i+1, 1, cap, n, a, dp));
        else profit = max(a[i] + solve(i+1, 1, cap-1, n, a, dp), solve(i+1, 0, cap, n, a, dp));
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(2, vector<long>(3, -1)));
        return solve(0, 1, 2, n, prices, dp);
    }
};