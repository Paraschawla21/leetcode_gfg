class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int s = groupSizes[i];
            mp[s].push_back(i);
            if (mp[s].size() == s)
            {
                ans.push_back(mp[s]);
                mp[s] = {};
            }
        }
        return ans;
    }
};