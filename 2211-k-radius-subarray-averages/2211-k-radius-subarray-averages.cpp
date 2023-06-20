class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long prefix[n];
        long suffix[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            suffix[i] = suffix[i+1] + nums[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i-k < 0 or i+k >= n)
            {
                ans[i] = -1;
            }
            else
            {
                long sum = suffix[i-k] - suffix[i] + nums[i] + prefix[i+k] - prefix[i];
                sum /= (2*k + 1);
                ans[i] = sum;
            }
        }
        return ans;
    }
};