class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> arr(n+1);
        int sum = 0;
        for (int i = 0; i < n; i++) if (customers[i] == 'N') sum++;
        arr[n] = sum;
        for (int i = n-1; i >= 0; i--)
        {
            if (customers[i] == 'Y') sum++;
            else sum--;
            arr[i] = sum;
        }
        int mini = INT_MAX;
        for (int i = 0; i <= n; i++) mini = min(mini, arr[i]);
        for (int i = 0; i <= n; i++) if (arr[i] == mini) return i;
        return n;
    }
};