class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (auto i : t) mp[i]++;
        for (auto i : s) mp[i]--;
        char ans;
        for (auto i : mp) if (i.second == 1) ans = i.first;
        return ans; 
    }
};