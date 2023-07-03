class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if (n != m) return false;
        // for (int i = 0; i < n-1; i++)
        // {
        //     for (int j = i+1; j < n; j++)
        //     {
        //         swap(s[i], s[j]);
        //         if (s == goal) return true;
        //         swap(s[i], s[j]);
        //     }
        // }
        // return false;

        if (s == goal)
        {
            unordered_map<char, int> mp;
            for (auto i : s) mp[i]++;
            for (auto i : mp) if (i.second > 1) return true;
        }

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != goal[i]) v.push_back(i);
        }
        if (v.size() != 2) return false;

        swap(s[v[0]], s[v[1]]);
        return s == goal;
    }
};