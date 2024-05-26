// Problem Link :- https://leetcode.com/problems/student-attendance-record-ii/

// Solved by Memoization Method
// Time Complexity :- O(n * 2 * 3)
// Space Complexity :- O(n * 2 * 3)

class Solution {
public:

    long mod = 1e9 + 7;

    int solve(int index, int absent, int late, vector<vector<vector<int>>> &dp)
    {
        if (index == -1)
            return 1;

        if (dp[index][absent][late] != -1)
            return dp[index][absent][late];

        long ways = solve(index - 1, absent, 2, dp) % mod;

        if (absent)
            ways = (ways + solve(index - 1, absent - 1, 2, dp) % mod) % mod;

        if (late)
            ways = (ways + solve(index - 1, absent, late - 1, dp) % mod) % mod;

        return dp[index][absent][late] = ways;
    }

    int checkRecord(int n) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));

        return solve(n - 1, 1, 2, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * 2 * 3)
// Space Complexity :- O(n * 2 * 3)

class Solution {
public:

    int checkRecord(int n) {
        
        long mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        for (int absent = 0; absent < 2; absent++)
        {
            for (int late = 0; late < 3; late++)
            {
                dp[0][absent][late] = 1;
            }
        }

        for (int index = 1; index <= n; index++)
        {
            for (int absent = 0; absent < 2; absent++)
            {
                for (int late = 0; late < 3; late++)
                {
                    long ways = dp[index - 1][absent][2] % mod;

                    if (absent)
                        ways = (ways + dp[index - 1][absent - 1][2] % mod) % mod;

                    if (late)
                        ways = (ways + dp[index - 1][absent][late - 1] % mod) % mod;

                    dp[index][absent][late] = ways;
                }
            }
        }

        return dp[n][1][2];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * 2 * 3)
// Space Complexity :- O(2 * 3)

class Solution {
public:

    int checkRecord(int n) {
        
        long mod = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int> (3, 1));

        for (int index = 1; index <= n; index++)
        {
            vector<vector<int>> temp(2, vector<int> (3));

            for (int absent = 0; absent < 2; absent++)
            {
                for (int late = 0; late < 3; late++)
                {
                    long ways = dp[absent][2] % mod;

                    if (absent)
                        ways = (ways + dp[absent - 1][2] % mod) % mod;

                    if (late)
                        ways = (ways + dp[absent][late - 1] % mod) % mod;

                    temp[absent][late] = ways;
                }
            }

            dp = temp;
        }

        return dp[1][2];
    }
};