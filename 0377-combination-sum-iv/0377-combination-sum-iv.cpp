class Solution {
public:
    int solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp, int n)
    {
        if (target == 0) return 1;
        if (i >= n or target < 0) return 0;
        if (dp[i][target] != -1) return dp[i][target];
        int take = solve(0, nums, target - nums[i], dp, n);
        int notTake = solve(i+1, nums, target, dp, n);
        return dp[i][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
        return solve(0, nums, target, dp, n);
    }
};