// Problem Link :- https://leetcode.com/problems/new-21-game/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n + 1);
        dp[0] = 1;
        double tempSum = (k > 0);
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = tempSum * 1.0/maxPts;

            if (i < k)
                tempSum += dp[i];

            if (i - maxPts >= 0 && i - maxPts < k)
                tempSum -= dp[i - maxPts];
        }

        double sum = accumulate(dp.begin() + k, dp.end(), 0.0);

        return sum;
    }
};