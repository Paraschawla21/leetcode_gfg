class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>> &grid, int &sum)
    {
        sum++;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            int x = i + delRow[k];
            int y = j + delCol[k];
            if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == 1)
            {
                dfs(x, y, grid, sum);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int sum = 0;
                    dfs(i, j, grid, sum);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};