class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = r + drow[i];
                int y = c + dcol[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
                {
                    q.push({x, y});
                    vis[x][y] = 1;
                    dis[x][y] = dis[r][c] + 1;
                }
            }
        }
        return dis;
    }
};
