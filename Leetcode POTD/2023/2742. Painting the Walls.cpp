// Problem Link :- https://leetcode.com/problems/painting-the-walls/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int solve (int index, int wallRem, int &n, vector<vector<int>> &dp, vector<int>& cost, vector<int>& time)
    {
        if (wallRem <= 0)
            return 0;

        if (index == n)
            return 1e9;

        if (dp[index][wallRem] != -1)
            return dp[index][wallRem];

        int paint = cost[index] + solve (index + 1, wallRem - time[index] - 1, n, dp, cost, time);
        int notPaint = solve (index + 1, wallRem, n, dp, cost, time);

        return dp[index][wallRem] = min(paint, notPaint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();
        vector<vector<int>> dp (n, vector<int> (n + 1, -1));

        return solve (0, n, n, dp, cost, time);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));

        for (int index = n; index >= 0; index--)
        {
            for (int wallRem = 0; wallRem <= n; wallRem++)
            {
                if (wallRem == 0)
                {
                    dp[index][wallRem] = 0;
                    continue;
                }

                if (index == n)
                {
                    dp[index][wallRem] = 1e9;
                    continue;
                }

                int notPaint = dp[index + 1][wallRem];
                int paint = cost[index] + dp[index + 1][max(0, wallRem - time[index] - 1)];

                dp[index][wallRem] = min(paint, notPaint);
            }
        }

        return dp[0][n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();
        vector<int> dp (n + 1, 0);

        for (int index = n; index >= 0; index--)
        {
            vector<int> temp (n + 1, 0);

            for (int wallRem = 0; wallRem <= n; wallRem++)
            {
                if (wallRem == 0)
                {
                    temp[wallRem] = 0;
                    continue;
                }

                if (index == n)
                {
                    temp[wallRem] = 1e9;
                    continue;
                }

                int notPaint = dp[wallRem];
                int paint = cost[index] + dp[max(0, wallRem - time[index] - 1)];

                temp[wallRem] = min(paint, notPaint);
            }

            dp = temp;
        }

        return dp[n];
    }
};