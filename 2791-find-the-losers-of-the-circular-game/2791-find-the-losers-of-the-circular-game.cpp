class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> visited(n, 0), ans;
        int i = 0;
        int turn = 1;
        while (!visited[i])
        {
            visited[i] = 1;
            i = (i + ((turn * k) % n)) % n;
            turn++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) ans.push_back(i+1);
        }
        return ans;
    }
};