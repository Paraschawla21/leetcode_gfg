class Solution {
public:
    int bfs(vector<vector<int>>& bombs, int &src)
    {
        vector<bool> visited(bombs.size(), false);
        queue<pair<pair<int, int>, int>> q;
        q.push({{bombs[src][0], bombs[src][1]}, bombs[src][2]});
        visited[src] = true;
        int count = 1;
        while (!q.empty())
        {
            long long x1 = q.front().first.first;
            long long y1 = q.front().first.second;
            long long r = q.front().second;
            q.pop();
            for (int i = 0; i < bombs.size(); i++)
            {
                if (!visited[i] == true)
                {
                    long long x2 = bombs[i][0];
                    long long y2 = bombs[i][1];
                    long long x = abs(x1 - x2);
                    long long y = abs(y1 - y2);
                    long long d = x*x + y*y;
                    long long r1 = r*r;
                    if (d <= r1)
                    {
                        count++;
                        visited[i] = true;
                        q.push({{bombs[i][0], bombs[i][1]}, bombs[i][2]});
                    }
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = INT_MIN;
        for (int i = 0; i < bombs.size(); i++)
        {
            ans = max(ans, bfs(bombs, i));
        }
        return ans;
    }
};