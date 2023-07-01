class Solution {
public:
    void solve(int idx, int &ans, vector<int> &cookies, int k, vector<int> &v)
    {
        if (idx == cookies.size())
        {
            int maxi = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                maxi = max(maxi, v[i]);
            }
            ans = min(ans, maxi);
            return;
        }
        for (int i = 0; i < k; i++)
        {
            v[i] += cookies[idx];
            solve(idx+1, ans, cookies, k, v);
            v[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> v(k);
        int ans = INT_MAX;
        solve(0, ans, cookies, k, v);
        return ans;
    }
};