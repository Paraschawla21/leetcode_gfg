class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[sum] = 1;
        int ans = 0;
        for (auto i : nums)
        {
            sum += i;
            int find = sum - k;
            if (mp.count(find) > 0) ans += mp[find];
            mp[sum]++;
        }
        return ans;
    }
};