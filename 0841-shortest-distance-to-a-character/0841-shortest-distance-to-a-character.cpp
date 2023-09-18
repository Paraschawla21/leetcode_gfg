class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == c)
                {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                if (s[j] == c)
                {
                    if (i - j < ans[i])
                    {
                        ans[i] = i - j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};