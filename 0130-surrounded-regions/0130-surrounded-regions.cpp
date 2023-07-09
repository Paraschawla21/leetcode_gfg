class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>> &board)
    {
        visited[i][j] = 1;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int x = i + drow[k];
            int y = j + dcol[k];
            if (x >= 0 and x < visited.size() and y >= 0 and y < visited[0].size() and !visited[x][y] and board[x][y] == 'O') dfs(x, y, visited, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O' and !visited[0][j]) dfs(0, j, visited, board);
            if (board[n-1][j] == 'O' and !visited[n-1][j]) dfs(n-1, j, visited, board);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' and !visited[i][0]) dfs(i, 0, visited, board);
            if (board[i][m-1] == 'O' and !visited[i][m-1]) dfs(i, m-1, visited, board);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' and !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};