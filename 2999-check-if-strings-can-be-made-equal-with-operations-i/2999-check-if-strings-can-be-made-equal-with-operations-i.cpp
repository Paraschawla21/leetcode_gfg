class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool even = (s1[0] == s2[0] and s1[2] == s2[2]) or (s1[0] == s2[2] and s1[2] == s2[0]);
        bool odd = (s1[1] == s2[1] and s2[3] == s1[3]) or (s1[1] == s2[3] and s1[3] == s2[1]);
        return even and odd;
    }
};