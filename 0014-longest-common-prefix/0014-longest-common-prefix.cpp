class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];
            int counter = 1;
            for (int j = 1; j < strs.size(); j++)
            {
                if (ch == strs[j][i])
                {
                    counter++;
                }
                else
                    return ans;
            }
            if (counter == strs.size())
                ans.push_back(ch);
        }
        return ans;
    }
};