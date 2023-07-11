class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) return 0;
        int i = 0;
        while (i < s.size() and s[i] == ' ') i++;
        s = s.substr(i);
        int sign = 1;
        if (s[0] == '-') sign = -1;
        long ans = 0;
        if (s[0] == '-' or s[0] == '+') i = 1;
        else i = 0;
        while (i < s.size())
        {
            if (s[0] == ' ' or !isdigit(s[i])) break;
            ans = ans * 10 + s[i] - '0';
            if (ans * sign < INT_MIN) return INT_MIN;
            if (ans * sign > INT_MAX) return INT_MAX;
            i++;
        }
        return ans * sign;
    }
};