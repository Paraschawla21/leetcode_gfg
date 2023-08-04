class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] and st.count(s.substr(j, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};