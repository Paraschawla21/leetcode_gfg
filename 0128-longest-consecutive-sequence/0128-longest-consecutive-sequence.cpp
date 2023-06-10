class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int ans = 1;
        // int cur = 1;
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     if (nums[i] == nums[i-1] + 1) cur++;
        //     else cur = 1;
        //     ans = max(ans, cur);
        // }
        // return ans;

        set<int> st;
        for (auto i : nums) st.insert(i);
        int ans = 0;
        for (auto i : nums)
        {
            if (!st.count(i-1))
            {
                int cur = 1;
                int num = i;
                while (st.count(num + 1))
                {
                    cur++;
                    num++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};