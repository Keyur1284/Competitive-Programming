// Problem Link :- https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Solved by Memoization Method
// Time Complexity :- O(n * target * faces)
// Space Complexity :- O(n * target)

class Solution {
public:

    long MOD = 1e9 + 7;

    int solve (int dice, int target, int &k, vector<vector<int>> &dp)
    {
        if (dice == 0)
            return (target == 0);

        if (target == 0)
            return 0;

        if (dp[dice][target] != -1)
            return dp[dice][target];

        long ways = 0;

        for (int face = 1; face <= k; face++)
        {
            if (target >= face)
            {
                ways += solve(dice - 1, target - face, k, dp) % MOD;
                ways %= MOD;
            }

            else
                break;
        }

        return dp[dice][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp (n + 1, vector<int> (target + 1, -1));
        return solve(n, target, k, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * target * faces)
// Space Complexity :- O(n * target)

class Solution {
public:

    long MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp (n + 1, vector<int> (target + 1, 0));
        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                long ways = 0;

                for (int face = 1; face <= k; face++)
                {
                    if (tar >= face)
                    {
                        ways += dp[dice - 1][tar - face];
                        ways %= MOD;
                    }

                    else
                        break;
                }

                dp[dice][tar] = ways;
            }
        }

        return dp[n][target];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * target * faces)
// Space Complexity :- O(target)

class Solution {
public:

    long MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        
        vector<int> dp (target + 1, 0);
        dp[0] = 1;

        for (int dice = 1; dice <= n; dice++)
        {
            vector<int> temp (target + 1, 0);

            for (int tar = 0; tar <= target; tar++)
            {
                long ways = 0;

                for (int face = 1; face <= k; face++)
                {
                    if (tar >= face)
                    {
                        ways += dp[tar - face];
                        ways %= MOD;
                    }

                    else
                        break;
                }

                temp[tar] = ways;
            }

            dp = temp;
        }

        return dp[target];
    }
};