class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != 1 + s2.size()) return false;
        int i = 0;
        int j = 0;
        while (i < s1.size())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else i++;
        }
        return i == s1.size() && j == s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), comp);
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxi) maxi = dp[i];
        }
        return maxi;
    }
};
