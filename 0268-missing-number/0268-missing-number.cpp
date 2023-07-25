class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int y = 0;
        for (int i = 0; i <= n; i++)
        {
            x += i;
        }
        for (auto i : nums) y += i;
        return x - y;
    }
};