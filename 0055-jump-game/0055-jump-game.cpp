class Solution {
public:
    bool dfs(int i, int n, vector<int> &nums, vector<int> &dp) {
        if(i >= n - 1) return true;
        if(dp[i] != -1) return dp[i];

        for(int j=1; j<=nums[i]; j++) {
            if(dfs(i + j, n, nums, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(0, n, nums, dp);
    }
};