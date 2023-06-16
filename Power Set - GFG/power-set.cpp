//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    	void solve(string &s, int n, vector<string>& ans, string &temp, int index)
    	{
    	    if (index == n)
    	    {
    	        if (temp.size()) ans.push_back(temp);
    	        return;
    	    }
    	    solve(s, n, ans, temp, index + 1);
    	    
    	    temp.push_back(s[index]);
    	    solve(s, n, ans, temp, index + 1);
    	    temp.pop_back();
    	    
    	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n= s.size();
		    vector<string> ans;
		  //  for (int num = 0; num <= (1 << n) - 1; num++)
		  //  {
		  //      string temp = "";
		  //      for (int i = 0; i < n; i++)
		  //      {
		  //          if (num & (1 << i))
		  //          {
		  //              temp += s[i];
		  //          }
		            
		  //      }
		  //      if (temp.size() > 0)
		  //      ans.push_back(temp);
		  //  }
		    string temp = "";
		    solve(s, n, ans, temp, 0);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends