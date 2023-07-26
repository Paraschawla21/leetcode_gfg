class Solution {
public:
    int requiredDays(vector<int> weights, int mid)
    {
        int n = weights.size();
        long sum = 0;
        long days = 1;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
            if (sum > mid)
            {
                days++;
                sum = weights[i];
            }
        }
        return (int)days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (requiredDays(weights, mid) <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};