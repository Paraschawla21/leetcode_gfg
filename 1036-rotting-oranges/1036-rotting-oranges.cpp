class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count1 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                if (grid[i][j] == 1) count1++;
            }
        }
        int ans = 0;
        int count2 = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans, t);
            for (int i = 0; i < 4; i++)
            {
                int x = r + drow[i];
                int y = c + dcol[i];
                if (x >= 0 and x < n and y >= 0 and y < m and !visited[x][y] and grid[x][y] == 1)
                {
                    q.push({{x, y}, t+1});
                    visited[x][y] = 2;
                    count2++;
                }
            }
        }
        if (count1 != count2) return -1;
        return ans;
    }
};