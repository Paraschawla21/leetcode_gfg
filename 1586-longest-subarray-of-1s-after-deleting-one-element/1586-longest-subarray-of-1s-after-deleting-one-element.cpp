class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0;
        int lastZeroIndex = -1;
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            if (nums[j] == 0)
            {
                i = lastZeroIndex + 1;
                lastZeroIndex = j;
            }
            maxLength = max(maxLength, j-i);
            j++;
        }
        return maxLength;
    }
};