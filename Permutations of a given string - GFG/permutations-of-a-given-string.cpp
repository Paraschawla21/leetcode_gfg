//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    	void solve(string &S, set<string> &st, int start, int end)
    	{
    	    if (start == end)
    	    {
    	        st.insert(S);
    	        return;
    	    }
    	    for (int i = start; i <= end; i++)
            {
                swap(S[start], S[i]);
                solve(S, st, start + 1, end);
                swap(S[start], S[i]);
            }
    	}
		vector<string>find_permutation(string S)
		{
		    int n = S.size();
		    set<string> st;
		    solve(S, st, 0, n-1);
		    vector<string> ans(st.begin(), st.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends