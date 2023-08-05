class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int curr = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i-1])
            {
                curr++;
                if (curr <= 1)
                {
                    nums[k] = nums[i];
                    k++;
                }
            }
            else
            {
                curr = 0;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};