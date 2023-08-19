class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int i = 0;
        stack<int> st2;
        stack<string> st1;
        int multiplier = 0;  // Store the multiplier as a variable
        
        while (i < n) {
            if (isdigit(s[i])) {
                multiplier = 0;
                while (isdigit(s[i])) {
                    multiplier = multiplier * 10 + (s[i] - '0');
                    i++;
                }
            } else if (s[i] == '[') {
                st2.push(multiplier);
                multiplier = 0;  // Reset the multiplier
                st1.push("[");
                i++;
            } else if (s[i] == ']') {
                string temp = "";
                while (st1.top() != "[") {
                    temp = st1.top() + temp;
                    st1.pop();
                }
                st1.pop();
                int it = st2.top();
                st2.pop();
                string str = "";
                while (it--) {
                    str += temp;
                }
                st1.push(str);
                i++;
            } else {
                st1.push(string(1, s[i]));
                i++;
            }
        }
        
        string ans = "";
        while (!st1.empty()) {
            ans = st1.top() + ans;
            st1.pop();
        }
        return ans;
    }
};
