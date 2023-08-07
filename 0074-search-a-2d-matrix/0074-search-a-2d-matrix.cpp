class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int en = n * m - 1;
        while (st <= en)
        {
            int mid = st + (en - st) / 2;
            int ele = matrix[mid / m][mid % m];
            if (ele == target) return true;
            if (ele > target) en = mid - 1;
            else st = mid + 1;
        }
        return false;
    }
};