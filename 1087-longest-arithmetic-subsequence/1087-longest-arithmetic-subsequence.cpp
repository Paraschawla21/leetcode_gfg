class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        unordered_map<int, int> dp[n];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int count = 1;
                // check if ans already present
                if (dp[j].count(diff)) count = dp[j][diff];
                dp[i][diff] = count + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};