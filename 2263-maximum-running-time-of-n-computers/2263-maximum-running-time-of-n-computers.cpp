class Solution {
public:
    typedef long long int ll;
    bool isPossible(vector<int> &a, ll mid, int n)
    {
        ll sum = 0;
        ll target = 1LL * n * mid;
        for (int i = 0; i < a.size(); i++)
        {
            sum += min(1LL * a[i], mid);
            if (sum >= target) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& a) {
        ll low = *min_element(a.begin(), a.end());
        ll high = accumulate(a.begin(), a.end(), 0LL) / n;
        ll ans = -1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (isPossible(a, mid, n))
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};