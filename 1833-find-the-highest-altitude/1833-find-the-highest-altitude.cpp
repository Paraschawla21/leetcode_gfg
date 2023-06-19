class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> arr(n+1);
        arr[0] = gain[0];
        for (int i = 1; i < n; i++)
        {
            gain[i] += gain[i-1];
        }
        for (auto i : gain) arr.push_back(i);
        int ans = INT_MIN;
        for (auto i : arr) ans = max(ans, i);
        return ans;
    }
};