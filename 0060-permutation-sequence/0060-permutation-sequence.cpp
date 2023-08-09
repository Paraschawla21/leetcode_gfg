class Solution {
public:
    void recur(string s, string temp, vector<bool> &vis, vector<string> &ans, int &cnt, int k){
      if(temp.size() == s.size()){
        ans.emplace_back(temp);
        cnt++;
        if(cnt == k) return;
      }
      for(int i = 0; i < s.size(); i++){
        if(!vis[i]){
          vis[i] = true;
          temp += s[i];
          recur(s, temp, vis, ans, cnt, k);
          temp.pop_back();
          vis[i] = false;
        }
        if(cnt == k) return;
      }
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> str;
        for (int i = 1; i <= n; i++)
        {
            str.push_back(i + '0');
        }
        for (auto i : str) cout << i << endl;
        while (k-- > 1)
        {
            next_permutation(str.begin(), str.end());
        }
        for (auto i : str)
        {
            ans.push_back(i);
        }
        return ans;
    }
};