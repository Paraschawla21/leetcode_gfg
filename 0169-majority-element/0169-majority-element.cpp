class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for (auto i : nums) mp[i]++;
        // int n = nums.size() / 2;
        // for (auto i : mp)
        // {
        //     if (i.second > n) return i.first;
        // }
        // return 0;

        // Moore's Voting Algorithm
        int n = nums.size();
        int count = 0;
        int ele;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                count = 1;
                ele = nums[i];
            }
            else if (ele == nums[i])
            {
                count++;
            }
            else count--;
        }

        // verification
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele) ans++;
        }
        if (ans > (n / 2)) return ele;
        return -1;
    }
};