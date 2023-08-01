class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        vector<int> arr = nums;
        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        vector<int> ans(k);
        for (int i = 0; i < n - k; i++)
        {
            arr.erase(find(arr.begin(), arr.end(), pq.top()));
            pq.pop();
        }
        for (int i = 0; i < k; i++)
        {
            ans[i] = arr[i];
        }
        return ans;
    }
};