class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        visited[i][j] = 1;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int x = i + drow[k];
            int y = j + dcol[k];
            if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and !visited[x][y] and grid[x][y] == 1)
            {
                dfs(x, y, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // first row and last row
        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] and grid[0][j] == 1) dfs(0, j, grid, visited);
            if (!visited[n-1][j] and grid[n-1][j] == 1) dfs(n-1, j, grid, visited);
        }
        // first column and last column
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] and grid[i][0] == 1) dfs(i, 0, grid, visited);
            if (!visited[i][m-1] and grid[i][m-1] == 1) dfs(i, m-1, grid, visited);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] and grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};