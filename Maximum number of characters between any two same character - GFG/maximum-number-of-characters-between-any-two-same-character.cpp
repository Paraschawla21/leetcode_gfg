//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int maxChars (string s)
{
    // your code here
    int n = s.size();
    unordered_map<char, int> mp;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            ans = max(ans, i - mp[s[i]] - 1);
        }
        else mp[s[i]] = i;
    }
    return ans;
}