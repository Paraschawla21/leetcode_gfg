class Solution {
public:
    bool solve(int i, int k, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (k == 0) return true;
        if (i == 0)
        {
           return (nums[i] == k); 
        }
        if (dp[i][k] != -1) return dp[i][k];
        bool notTake = solve(i-1, k, nums, dp);
        bool take = false;
        if (nums[i] <= k) take = solve(i-1, k-nums[i], nums, dp);
        return dp[i][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 != 0) return false;
        int k = sum / 2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return solve(n-1, k, nums, dp);
        // vector<vector<bool>> dp(n, vector<bool>(k+1, false));
        // for (int i = 0; i < n; i++)
        // {
        //     dp[i][0] = true;
        // }
        // dp[0][nums[0]] = true;
        // for (int i = 1; i < n; i++)
        // {
        //     for (int target = 1; target <= k; target++)
        //     {
        //         bool notTake = dp[i-1][target];
        //         bool take = false;
        //         if (nums[i] <= target) take = dp[i-1][target - nums[i]];
        //         dp[i][target] = take | notTake;
        //     }
        // }
        // return dp[n-1][k];
    }
};