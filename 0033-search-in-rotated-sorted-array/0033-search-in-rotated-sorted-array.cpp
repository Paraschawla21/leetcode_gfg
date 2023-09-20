class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int en = n-1;
        while (l < en)
        {
            int mid = l + (en - l) / 2;
            if(nums[mid] == target) return mid;
            if (nums[mid] > nums[en]) l = mid + 1;
            else en = mid;
        }
        cout << l;
        int pivot = l;
        l = 0;
        en = pivot - 1;
        while (l <= en)
        {
            int mid = l + (en - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) en = mid - 1;
            else l = mid + 1;
        }
        l = pivot;
        en = n - 1;
        while (l <= en)
        {
            int mid = l + (en - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) en = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};