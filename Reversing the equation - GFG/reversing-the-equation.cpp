//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            int i = 0;
            int n = s.size();
            while (i < n)
            {
                int j = i;
                while (j < n && s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/')
                {
                    j++;
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            reverse(s.begin(), s.end());
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends