class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j, int &count)
    {
        visited[i][j] = true;
        if (i >= grid.size() || j >= grid[0].size()) return;
        if (visited[i][j] || grid[i][j] >= 0) return;
        count++;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!visited[i][j] && grid[i][j] < 0)
                {
                    count++;
                    dfs(grid, visited, i, j, count);
                }
            }
        }
        return count;
    }
};