class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int ans = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            prefix *= a[i];
            suffix *= a[n-i-1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};