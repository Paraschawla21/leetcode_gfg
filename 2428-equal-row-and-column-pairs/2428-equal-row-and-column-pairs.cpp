class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[grid[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> col;
            for (int j = 0; j < n; j++)
            {
                col.push_back(grid[j][i]);
            }
            ans += mp[col];
        }
        return ans;
    }
};