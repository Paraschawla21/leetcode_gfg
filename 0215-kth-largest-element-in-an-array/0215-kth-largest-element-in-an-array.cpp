class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto i : nums) pq.push(i);
        int ele;
        while (k--)
        {
            ele = pq.top();
            pq.pop();
        }
        return ele;
    }
};