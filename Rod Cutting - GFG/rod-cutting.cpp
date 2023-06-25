//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i, int k, int price[], vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return k * price[0];
        }
        if (dp[i][k] != -1) return dp[i][k];
        int notTake = solve(i-1, k, price, dp);
        int take = INT_MIN;
        int rodLength = i + 1;
        if (rodLength <= k) take = price[i] + solve(i, k - rodLength, price, dp);
        return dp[i][k] = max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends