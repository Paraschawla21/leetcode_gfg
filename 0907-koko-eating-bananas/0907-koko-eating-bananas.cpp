class Solution {
public:
    int isPossible(vector<int> piles, int mid, int h)
    {
        int n = piles.size();
        int hours = 0;
        for (int i = 0; i < n; i++)
        {
            hours += (piles[i] / mid);
            piles[i] %= mid;
            if (piles[i] > 0) hours++;
            if (hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int k = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h))
            {
                k = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return k;
    }
};