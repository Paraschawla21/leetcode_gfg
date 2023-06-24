class Solution {
public:
    int solve(int i, vector<int> &a, int k, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (k % a[0] == 0) return k / a[0];
            return 1e9;
        }
        if (dp[i][k] != -1) return dp[i][k];
        int notTake = solve(i-1, a, k, dp);
        int take = 1e9;
        if (a[i] <= k) take = 1 + solve(i, a, k - a[i], dp);
        return dp[i][k] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n-1, coins, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};