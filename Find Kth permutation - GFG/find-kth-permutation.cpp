//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i + '0');
        }
        string str = "";
        while (k-- > 1)
        {
            next_permutation(arr.begin(), arr.end());
        }
        for (auto i : arr)
        {
            str.push_back(i);
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends