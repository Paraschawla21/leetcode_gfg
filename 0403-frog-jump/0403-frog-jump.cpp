class Solution {
public:
    unordered_map<int, int> mp;
    int n;
    bool solve(int currStoneIdx, int prevJump, vector<int> &stones, vector<vector<int>> &dp)
    {
        if (currStoneIdx == n - 1) return true;
        if (dp[currStoneIdx][prevJump] != -1) return dp[currStoneIdx][prevJump];
        bool flag = false;
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++)
        {
            if (nextJump > 0)
            {
                int nextStone = stones[currStoneIdx] + prevJump;
                if (mp.find(nextStone) != mp.end())
                {
                    flag = flag or solve(mp[nextStone], nextJump, stones, dp);
                }
            }
        }
        return dp[currStoneIdx][prevJump] = flag;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) mp[stones[i]] = i;
        return solve(0, 0, stones, dp);
    }
};