//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
      int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
      {
          if (i < 0 or j < 0) return 0;
          if (dp[i][j] != -1) return dp[i][j];
          if (s1[i] == s2[j]) dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
          else {
            dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
        }
        
        return dp[i][j];
      }
    int longestPalinSubseq(string s1) {
        //code here
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n-1, n-1, s1, s2, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends