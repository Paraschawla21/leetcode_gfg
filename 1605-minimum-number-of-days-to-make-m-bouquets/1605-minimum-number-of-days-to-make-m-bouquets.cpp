class Solution {
public:
    bool isPossible(vector<int> arr, int mid, int m, int k, int n)
    {
        int count = 0;
        int bouquet = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid) count++;
            else
            {
                bouquet += (count / k);
                count = 0;
            }
        }
        bouquet += (count / k);
        if (bouquet >= m) return true;
        return false;
    }
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        long long int val = 1LL * m * 1LL * k;
        if (val > n) return -1;
        int low = *min_element(a.begin(), a.end());
        int high = *max_element(a.begin(), a.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(a, mid, m, k, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};