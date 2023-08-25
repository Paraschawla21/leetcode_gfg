class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = accumulate(nums.begin() + 1, nums.end(), 0);
        if (left == right) return 0;
        for (int i = 1; i < n; i++)
        {
            int left = accumulate(nums.begin(), nums.begin() + i, 0);
            int right = accumulate(nums.begin() + i + 1, nums.end(), 0);
            if (left == right) return i;
        }
        return -1;
    }
};