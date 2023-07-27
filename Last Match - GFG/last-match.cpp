//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string A, string B){
        //Code Here
        int a = A.size();
        int b = B.size();
        vector<int> p(b, 0);
        for (int i = 1; i < b; i++)
        {
            int j = p[i - 1];
            while (j > 0 and B[i] != B[j])
            {
                j = p[j - 1];
            }
            if (B[i] == B[j])
            {
                j++;
            }
            p[i] = j;
        }
        int i = 0;
        int j = 0;
        int pos = -1;
        while (i < a)
        {
            if (A[i] == B[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0) j = p[j - 1];
                else i++;
            }
            if (j == b)
            {
                pos = i - b + 1;
            }
        }
        return pos;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends