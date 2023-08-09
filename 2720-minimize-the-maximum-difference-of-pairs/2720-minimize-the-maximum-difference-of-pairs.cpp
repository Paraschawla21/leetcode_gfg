class Solution {
public:
    bool isValid(int mid, vector<int> &nums, int p)
    {
        int i = 0;
        int count = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i+1] - nums[i] <= mid)
            {
                count++;
                i += 2;
            }
            else i += 1;
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans;
        while (low <= high)
        {
            int mid = low + (high - low)/2;
            if (isValid(mid, nums, p))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};