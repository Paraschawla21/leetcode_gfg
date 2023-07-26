class Solution {
public:
    double isPossible(vector<int> &dist, int mid)
    {
        int n = dist.size();
        double time = 0.0;
        for (int i = 0; i < n - 1; i++)
        {
            time += ceil((double)dist[i] / (double)mid);
        }
        time += ((double)dist[n-1] / (double)mid);
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isPossible(dist, mid) <= hour)
            {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};