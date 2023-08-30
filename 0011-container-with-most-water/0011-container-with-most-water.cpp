class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        long ans = 0;
        while (l < r)
        {
            long area = 0;
            area += (min(height[l], height[r]) * (r - l));
            ans = max(ans, area);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};