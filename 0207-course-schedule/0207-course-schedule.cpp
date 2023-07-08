class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for (auto i : a)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(n);
        for (int i = 0; i < n; i++)
        {
            for (auto neighbour : adj[i])
            {
                indegree[neighbour]++;
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
            topo.push_back(node);
            q.pop();
            for (int neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        return topo.size() == n;
    }
};