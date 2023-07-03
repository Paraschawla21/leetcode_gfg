class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for (auto i : nums)
        {
            ans = (ans ^ i) & ~count;
            count = (count ^ i) & ~ans;
        }
        return ans;
    }
};