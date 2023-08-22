class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n)
        {
            n--;
            int rem = n % 26;
            char temp = 'A' + rem;
            ans = temp + ans;
            n /= 26;
        }
        return ans;
    }
};