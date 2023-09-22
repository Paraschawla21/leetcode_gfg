class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[sum] = i;
        }
        if (sum < x) return -1;
        int remainingSum = sum - x;
        int maxi = INT_MIN;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int findSum = sum - remainingSum;
            if (mp.count(findSum))
            {
                int idx = mp[findSum];
                int len = i - idx;
                maxi = max(maxi, len);
            }
        }
        if (maxi != INT_MIN) return n - maxi;
        return -1;
    }
};