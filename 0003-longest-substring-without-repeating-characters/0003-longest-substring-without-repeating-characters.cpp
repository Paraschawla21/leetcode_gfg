class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int length = 0;
        int ans = 1;
        unordered_map<char, int> mp;
        int x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            length++;
            while (mp[s[i]] > 1)
            {
                mp[s[x]]--;
                length--;
                x++;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};