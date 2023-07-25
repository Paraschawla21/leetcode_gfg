class Solution {
public:
    vector<int> temp;
    int merge(int low, int high, int mid, vector<int> &nums)
    {
        long long count = 0;
        temp.clear();
        int left = low;
        int right = mid + 1;
        while (left <= mid and right <= high)
        {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else
            {
                count += mid - left + 1;
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
        return count;
    }
    int mergeSort(int low, int high, vector<int> &nums)
    {
        long long count = 0;
        if (low >= high) return count;
        int mid = low + (high - low) / 2;
        count += mergeSort(low, mid, nums);
        count += mergeSort(mid + 1, high, nums);
        count += merge(low, high, mid, nums);
        return count;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        // int local = 0;
        // int global = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (nums[i] > nums[j]) global++;
        //     }
        // }
        // for (int i = 0; i < n-1; i++)
        // {
        //     if (nums[i] > nums[i+1]) local++;
        // }
        // if (local == global) return true;
        // return false;

        int local = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (nums[i] > nums[i+1]) local++;
        }
        int global = mergeSort(0, n-1, nums);
        return local == global;
    }
};