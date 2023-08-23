class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int ans = 0;
        long long sum = 0;
        int i = 1;
        while (true)
        {
            sum += i;
            i++;
            ans++;
            if (sum == target) return ans;
            if (sum > target)
            {
                if ((sum - target) % 2 == 0) return ans;
            }
        }
        return ans;
    }
};