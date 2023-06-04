class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, vector<bool> &visited, int i)
    {
        if (visited[i]) return;
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1) dfs(isConnected, n, visited, j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(isConnected, n, visited, i);
            }
        }
        return ans;
    }
};