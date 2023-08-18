class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto i : roads)
        {
            int u = i[0];
            int v = i[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int iRank = adj[i].size();
                int jRank = adj[j].size();
                int total = iRank + jRank;
                if (adj[i].find(j) != adj[i].end()) total -= 1;
                ans = max(ans, total);
            }
        }
        return ans;
    }
};