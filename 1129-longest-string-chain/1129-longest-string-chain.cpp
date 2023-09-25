class Solution {
public:
    static bool comparator(string &a, string &b)
    {
        return a.length() < b.length();
    }
    bool ifPredecessor(string &s1, string &s2)
    {
        if (s1.length() + 1 != s2.length()) return false;
        int index = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s1[index] == s2[i]) index++;
        }
        if (index == s1.size()) return true;
        return false;
    }
    int solve(int i, int j, vector<string> &words, vector<vector<int>> &dp)
    {
        if (i == words.size()) return 0;
        if (dp[i][j+1] != -1) return dp[i][j+1];
        int take = 0;
        if (j == -1 or ifPredecessor(words[j], words[i]))
        {
            take = 1 + solve(i+1, i, words, dp);
        }
        int notTake = solve(i+1, j, words, dp);
        return dp[i][j+1] = max(take, notTake);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        int n = words.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
        return solve(0, -1, words, dp);
    }
};