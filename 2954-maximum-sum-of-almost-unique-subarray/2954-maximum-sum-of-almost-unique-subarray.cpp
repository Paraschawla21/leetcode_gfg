class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < k - 1)
            {
                mp[nums[i]]++;
                sum += nums[i];
            }
            else
            {
                mp[nums[i]]++;
                sum += nums[i];
                if (mp.size() >= m) ans = max(ans, sum);
                sum -= nums[j];
                mp[nums[j]]--;
                if (mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
        }
        return ans;
    }
};