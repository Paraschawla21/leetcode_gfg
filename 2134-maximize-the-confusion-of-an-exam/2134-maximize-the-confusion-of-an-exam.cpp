class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        unordered_map<char, int> mp;
        while (j < n)
        {
            mp[s[j]]++;
            int mini = min(mp['T'], mp['F']);
            while (mini > k)
            {
                mp[s[i]]--;
                i++;
                mini = min(mp['T'], mp['F']);
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};