// Problem Link :- https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

// Solved by Memoization Method
// Time Complexity :- O(steps * min(steps, arrLen))
// Space Complexity :- O(steps * min(steps, arrLen))

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int index, int steps, int arrLen, vector<vector<int>> &dp)
    {
        if (steps == 0)
            return (index == 0);

        if (dp[index][steps] != -1)
            return dp[index][steps];

        int ways = 0;

        if (index > 0)
        {
            ways += solve(index - 1, steps - 1, arrLen, dp);
            ways %= MOD;
        }

        ways += solve(index, steps - 1, arrLen, dp);
        ways %= MOD;

        if (index + 1 < arrLen)
        {
            ways += solve(index + 1, steps - 1, arrLen, dp);
            ways %= MOD;
        }

        return dp[index][steps] = ways;
    }

    int numWays(int steps, int arrLen) {
        
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp (arrLen, vector<int> (steps + 1, -1));

        return solve (0, steps, arrLen, dp);
    }   
};



// Solved by Tabulation Method
// Time Complexity :- O(steps * min(steps, arrLen))
// Space Complexity :- O(steps * min(steps, arrLen))

class Solution {
public:

    int MOD = 1e9 + 7;

    int numWays(int steps, int arrLen) {
        
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp (arrLen, vector<int> (steps + 1, 0));

        dp[0][0] = 1;

        for (int j = 1; j <= steps; j++)
        {
            for (int i = 0; i < arrLen; i++)
            {

                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
                
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;

                if (i + 1 < arrLen)
                {
                    dp[i][j] += dp[i + 1][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[0][steps];
    }   
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(steps * min(steps, arrLen))
// Space Complexity :- O(min(steps, arrLen))

class Solution {
public:

    int MOD = 1e9 + 7;

    int numWays(int steps, int arrLen) {
        
        arrLen = min(steps, arrLen);
        vector<int> dp (arrLen, 0);

        dp[0] = 1;

        for (int j = 1; j <= steps; j++)
        {
            vector<int> temp (arrLen, 0);

            for (int i = 0; i < arrLen; i++)
            {

                if (i > 0)
                {
                    temp[i] += dp[i - 1];
                    temp[i] %= MOD;
                }
                
                temp[i] += dp[i];
                temp[i] %= MOD;

                if (i + 1 < arrLen)
                {
                    temp[i] += dp[i + 1];
                    temp[i] %= MOD;
                }
            }

            dp = temp;
        }

        return dp[0];
    }   
};