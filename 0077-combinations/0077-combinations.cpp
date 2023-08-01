class Solution {
public:
    void solve(int i, int k, int n, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j <= n; j++)
        {
            temp.push_back(j);
            solve(j+1, k-1, n, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, ans, temp);
        return ans;
    }
};