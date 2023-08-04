class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        // for (int i = 0; i < queries.size(); i++)
        // {
        //     int xorr = 0;
        //     for (int j = queries[i][0]; j <= queries[i][1]; j++)
        //     {
        //         xorr ^= arr[j];
        //     }
        //     ans.push_back(xorr);
        // }
        // return ans;
        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i-1] ^ arr[i];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == 0) ans.push_back(arr[end]);
            else ans.push_back(arr[start - 1] ^ arr[end]);
        }
        return ans;
    }
};