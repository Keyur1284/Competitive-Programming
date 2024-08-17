// Problem Link :- https://leetcode.com/problems/maximum-number-of-points-with-cost/

// Solved by Tabulation Method
// Time Complexity :- O(m * n)
// Space Complexity :- O(n)

class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {

        int m = points.size(), n = points[0].size();
        vector<long long> dp(n, 0);

        for (auto &row : points)
        {
            vector<long long> leftMax(n, 0), rightMax(n, 0);
            leftMax[0] = dp[0];
            rightMax[n - 1] = dp[n - 1];

            for (int j = 1; j < n; j++)
                leftMax[j] = max(leftMax[j - 1] - 1, dp[j]);

            for (int j = n - 2; j >= 0; j--)
                rightMax[j] = max(rightMax[j + 1] - 1, dp[j]);

            for (int j = 0; j < n; j++)
                dp[j] = max(leftMax[j], rightMax[j]) + row[j];
        }

        return *max_element(dp.begin(), dp.end());
    }
};



class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {

        int m = points.size(), n = points[0].size();
        vector<long long> dp(n, 0);

        for (auto &row : points)
        {
            vector<long long> prev(n, 0);
            long long leftMax = 0, rightMax = 0;

            for (int j = 0; j < n; j++)
            {
                leftMax = max(leftMax - 1, dp[j]);
                prev[j] = max(prev[j], leftMax + row[j]);
            }

            for (int j = n - 1; j >= 0; j--)
            {
                rightMax = max(rightMax - 1, dp[j]);
                prev[j] = max(prev[j], rightMax + row[j]);
            }

            dp = prev;
        }

        return *max_element(dp.begin(), dp.end());
    }
};