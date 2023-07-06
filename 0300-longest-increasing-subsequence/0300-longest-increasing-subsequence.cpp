class Solution {
public:
    int solve(int i, int prev, vector<int> &a, int n, vector<vector<int>> &dp)
    {
        if (i == n) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];
        int notTake = 0 + solve(i+1, prev, a, n, dp);
        int take = 0;
        if (prev == -1 or a[i] > a[prev])
        {
            take = 1 + solve(i+1, i, a, n, dp);
        }
        int ans = max(take, notTake);
        return dp[i][prev+1] = ans;

    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> ans;
        // for (int num : nums)
        // {
        //     if (ans.empty() || ans[ans.size() - 1] < num)
        //     {
        //         ans.push_back(num);
        //     }
        //     else
        //     {
        //         // Find the index of the first element in ans which is >= num
        //         auto it = lower_bound(ans.begin(), ans.end(), num);
        //         *it = num;
        //     }
        // }
        // return ans.size();
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, n, dp);
    }
};