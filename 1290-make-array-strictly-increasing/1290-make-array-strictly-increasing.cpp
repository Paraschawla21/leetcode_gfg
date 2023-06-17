class Solution {
public:
    int solve(map<pair<int, int>, int> &dp, int prev, int i, vector<int> &arr1, vector<int> &arr2)
    {
        if (i == arr1.size()) return 0;
        if (dp.find({i, prev}) != dp.end()) return dp[{i, prev}];
        int ans = INT_MAX / 2;
        int nextIndex = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        // keep it
        if (arr1[i] > prev)
        {
            ans = min(ans, solve(dp, arr1[i], i+1, arr1, arr2));
        }
        // replace it
        if (nextIndex < arr2.size())
        {
            ans = min(ans, solve(dp, arr2[nextIndex], i+1, arr1, arr2) + 1);
        }
        return dp[{i, prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = solve(dp, INT_MIN, 0, arr1, arr2);
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};