class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) return false;
        int target = sum / 3;
        int currSum = 0;
        int count = 0;
        for (int i = 0; i < n-1; i++)
        {
            currSum += arr[i];
            if (currSum == target)
            {
                currSum = 0;
                count++;
            }
            if (count == 2) return true;
        }
        return false;
    }
};