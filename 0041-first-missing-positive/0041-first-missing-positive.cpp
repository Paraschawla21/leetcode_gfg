class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto i : nums) st.insert(i);
        int maxi = nums.size();
        int ans = 1;
        for (int i = 1; i <= maxi+1; i++)
        {
            if (st.find(i) == st.end())
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};