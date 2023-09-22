class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int ones = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1) ones++;
            }
            arr.push_back({ones, i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = arr[i].second;
        }
        return ans;
    }
};