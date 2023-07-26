class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];

            adj[v].push_back(u);
        }
        vector<int> indegree(n);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        if (topo.size() != n) return {};
        return topo;
    }
};