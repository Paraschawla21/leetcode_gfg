class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) left[i] = 0;
            else left[i] = st.top() + 1;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        long ans = 0;
        for (int i = n - 1;i >= 0; i--)
        {
            while (!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            if (st.empty()) right[i] = n-1;
            else right[i] = st.top() - 1;
            st.push(i);
            long area = heights[i] * (right[i] - left[i] + 1);
            ans = max(ans, area);
        }
        return (int) ans;
    }
};