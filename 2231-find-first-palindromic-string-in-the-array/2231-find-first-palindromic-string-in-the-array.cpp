class Solution {
public:
    bool isPalindrome(string s)
    {
        int st = 0;
        int en = s.size() - 1;
        while (st <= en)
        {
            if (s[st++] != s[en--]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto i : words)
        {
            if (isPalindrome(i)) return i;
        }
        return "";
    }
};