class Solution {
public:
    // static bool comparator(vector<int> &a, vector<int> &b)
    // {
    //     return a[1] < b[1];
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> arr = intervals;
        arr.push_back(newInterval);
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() or ans.back()[1] < arr[i][0]) ans.push_back(arr[i]);
            else ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        return ans;
    }
};