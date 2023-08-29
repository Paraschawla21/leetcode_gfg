class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // vector<int> next(m, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            while (!st.empty() and nums2[i] > nums2[st.top()])
            {
                // next[st.top()] = nums2[i];
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums1[i]) != mp.end()) ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};