class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n == 1) return s;
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
            if (mp[i] > (n+1) / 2) return "";
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        string ans = "";
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        while (pq.size() > 1)
        {
            auto firstPair = pq.top();
            pq.pop();
            auto secondPair = pq.top();
            pq.pop();

            ans += firstPair.second;
            ans += secondPair.second;

            if (--firstPair.first > 0) pq.push(firstPair);
            if (--secondPair.first > 0) pq.push(secondPair);
        }
        if (!pq.empty()) ans += pq.top().second;
        return ans;
    }
};