class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfsVisited, vector<vector<int>>& graph)
    {
        visited[node] = 1;
        dfsVisited[node] = 1;
        for (auto neighbour : graph[node])
        {
            if (!visited[neighbour] and dfs(neighbour, visited, dfsVisited, graph)) return true;
            else if (dfsVisited[neighbour]) return true;
        }
        dfsVisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int e = graph[0].size();
        vector<int> visited(n, 0);
        vector<int> dfsVisited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, dfsVisited, graph);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (dfsVisited[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};