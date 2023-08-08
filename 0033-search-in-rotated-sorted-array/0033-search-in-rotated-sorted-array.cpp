class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        int pivot = low;
        low = 0;
        high = pivot - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1; 
        }
        low = pivot;
        high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};