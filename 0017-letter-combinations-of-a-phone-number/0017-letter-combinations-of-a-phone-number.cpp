class Solution {
public:
    void solve(int i, vector<string> &map, string &digits, vector<string> &ans, string &temp)
    {
        if (i >= digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int num = digits[i] - '0';
        string val = map[num];
        for (int j = 0; j < val.size(); j++)
        {
            temp.push_back(val[j]);
            solve(i+1, map, digits, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        string temp = "";
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, map, digits, ans, temp);
        return ans;
    }
};