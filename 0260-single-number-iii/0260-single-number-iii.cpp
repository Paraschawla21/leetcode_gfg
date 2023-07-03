class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (auto i : nums) xorr ^= i;
        int index = 0;
        while (xorr)
        {
            if (xorr & 1) break;
            index++;
            xorr >>= 1;
        }
        int xor1 = 0;
        int xor2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & (1 << index))
            {
                xor1 ^= nums[i];
            }
            else xor2 ^= nums[i];
        }
        return {xor1, xor2};
    }
};