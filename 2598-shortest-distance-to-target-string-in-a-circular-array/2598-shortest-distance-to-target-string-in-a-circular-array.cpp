class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                ans = min({ans, abs(startIndex - i), n - abs(startIndex - i)});
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
