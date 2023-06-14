//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
        // sort(A, A + N, greater<int>());  // 7 4 2 2 1
        long long ans = 0;
        priority_queue<int> p;
        for (int i = 0; i < N; i++)
        {
            p.push(A[i]);
        }
        while (K-- and p.size())
        {
            int ele = p.top();
            p.pop();
            ans += ele;
            if (ele > 1)
            {
                p.push(ele/2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends