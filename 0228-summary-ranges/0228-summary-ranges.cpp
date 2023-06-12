class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        while (i < nums.size())
        {
            int low = i;
            int high = i;
            while (high + 1 < nums.size() and nums[high + 1] == nums[high] + 1)
            {
                high++;
            }
            if (high > low)
            {
                ans.push_back(to_string(nums[low]) + "->" + to_string(nums[high]));
            }
            else ans.push_back(to_string(nums[high]));
            i = high + 1;
        }
        return ans;
    }
};