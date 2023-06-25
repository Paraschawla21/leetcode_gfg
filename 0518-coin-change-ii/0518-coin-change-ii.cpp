class Solution {
public:
    int solve(int i, int k, vector<int> &a, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return (k % a[0] == 0);
        }
        if (dp[i][k] != -1) return dp[i][k];
        int notTake = solve(i-1, k, a, dp);
        int take = 0;
        if (a[i] <= k) take = solve(i, k - a[i], a, dp);
        return dp[i][k] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n-1, amount, coins, dp);
    }
};