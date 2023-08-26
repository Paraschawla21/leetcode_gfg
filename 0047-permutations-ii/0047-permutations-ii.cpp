class Solution {
public:
    void solve(int i, int n, vector<int> nums, set<vector<int>> &st)
    {
        if (i >= n)
        {
            st.insert(nums);
            return;
        }
        for (int j = i; j < n; j++)
        {
            swap(nums[i], nums[j]);
            solve(i+1, n, nums, st);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        solve(0, n, nums, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};