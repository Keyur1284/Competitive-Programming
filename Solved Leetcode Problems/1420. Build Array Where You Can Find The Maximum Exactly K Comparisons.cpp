// Problem Link :- https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

// Solved by Memoization Method
// Time Complexity :- O(n*m^2*k)
// Space Complexity :- O(n*m*k)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int index, int maxSoFar, int rem, int m, vector<vector<vector<int>>> &dp)
    {
        if (index == 0)
            return (rem == 0);

        if (rem < 0)
            return 0;

        if (dp[index][maxSoFar][rem] != -1)
            return dp[index][maxSoFar][rem];

        int count = 0;

        for (int num = 1; num <= maxSoFar; num++)
        {
            count += solve(index - 1, maxSoFar, rem, m, dp);
            count %= MOD;
        }

        for (int num = maxSoFar + 1; num <= m; num++)
        {
            count += solve(index - 1, num, rem - 1, m, dp);
            count %= MOD;
        }

        return dp[index][maxSoFar][rem] = count;
    }

    int numOfArrays(int n, int m, int k) {
        
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));

        return solve(n, 0, k, m, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n*m^2*k)
// Space Complexity :- O(n*m*k)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k) {
        
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, 0)));

        for (int maxSoFar = 0; maxSoFar <= m; maxSoFar++)
            dp[0][maxSoFar][0] = 1;

        for (int index = 1; index <= n; index++)
        {
            for (int maxSoFar = 0; maxSoFar <= m; maxSoFar++)
            {
                for (int rem = 0; rem <= k; rem++)
                {
                    int count = 0;

                    for (int num = 1; num <= maxSoFar; num++)
                    {
                        count += dp[index - 1][maxSoFar][rem];
                        count %= MOD;
                    }

                    if (rem > 0)
                    {
                        for (int num = maxSoFar + 1; num <= m; num++)
                        {
                            count += dp[index - 1][num][rem - 1];
                            count %= MOD;
                        }
                    }

                    dp[index][maxSoFar][rem] = count;
                }
            }
        }

        return dp[n][0][k];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n*m^2*k)
// Space Complexity :- O(m*k)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k) {
        
        vector<vector<int>> dp (m + 1, vector<int> (k + 1, 0));

        for (int maxSoFar = 0; maxSoFar <= m; maxSoFar++)
            dp[maxSoFar][0] = 1;

        for (int index = 1; index <= n; index++)
        {
            vector<vector<int>> temp (m + 1, vector<int> (k + 1, 0));

            for (int maxSoFar = 0; maxSoFar <= m; maxSoFar++)
            {
                for (int rem = 0; rem <= k; rem++)
                {
                    int count = 0;

                    for (int num = 1; num <= maxSoFar; num++)
                    {
                        count += dp[maxSoFar][rem];
                        count %= MOD;
                    }

                    if (rem > 0)
                    {
                        for (int num = maxSoFar + 1; num <= m; num++)
                        {
                            count += dp[num][rem - 1];
                            count %= MOD;
                        }
                    }

                    temp[maxSoFar][rem] = count;
                }
            }

            dp = temp;
        }

        return dp[0][k];
    }
};