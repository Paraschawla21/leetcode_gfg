#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);
        
        if (first == nums.end() || *first != target) {
            // Return [-1, -1] if target is not found
            return {-1, -1};
        }
        
        int firstPos = distance(nums.begin(), first);
        int lastPos = distance(nums.begin(), prev(last));
        
        return {firstPos, lastPos};
    }
};
