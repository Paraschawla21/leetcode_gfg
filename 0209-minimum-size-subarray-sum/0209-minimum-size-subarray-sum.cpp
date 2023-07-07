class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = n;
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                sum -= nums[i];
                i++;
                ans = min(ans, j-i+1);
            }
            j++;
        }
        if (ans == n) return 0;
        return ans + 1;
    }
};