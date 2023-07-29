class Solution {
public:
vector<pair<double, double>> v = {{100.00, 0.00}, {75.00, 25.00}, {50.00, 50.00}, {25.00, 75.00}};
    double solve(double a, double b, vector<vector<double>> &dp)
    {
        if (a <= 0 and b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] != -1.0) return dp[a][b];
        double prob = 0.0;
        for (auto i : v)
        {
            double p1 = i.first;
            double p2 = i.second;
            prob += solve(a - p1, b - p2, dp);
        }
        return dp[a][b] = 0.25 * prob;
    }
    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return solve(n, n, dp);
    }
};