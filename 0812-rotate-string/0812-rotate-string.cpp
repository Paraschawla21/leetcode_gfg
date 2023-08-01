class Solution {
public:
    bool rotateString(string s, string g) {
        if (s == g) return true;
        for (int i = 0; i < s.size(); i++)
        {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == g) return true;
        }
        return false;
    }
};