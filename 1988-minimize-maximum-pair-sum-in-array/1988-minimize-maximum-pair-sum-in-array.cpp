class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> ans;
        int st = 0;
        int en = n - 1;
        while (st < en)
        {
            ans.push_back(nums[st++] + nums[en--]);
        }
        long anss = -1e9;
        for (auto i : ans)
        {
            anss = max(anss, i);
        }
        return anss;
    }
};