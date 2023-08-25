class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while (l < h)
        {
            string temp = "";
            temp += to_string(nums[l++]);
            temp += to_string(nums[h--]);
            ans += stoll(temp);
        }
        if (l == h) ans += nums[l];
        return ans;
    }
};