class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for (auto i : s) mp[i]++;
        unordered_set<int> st;
        int ans = 0;
        for (auto i : mp)
        {
            while (i.second > 0 and st.find(i.second) != st.end())
            {
                i.second--;
                ans++;
            }
            st.insert(i.second);
        }
        return ans;
    }
};