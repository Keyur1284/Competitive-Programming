// Problem Link :- https://leetcode.com/problems/count-ways-to-build-good-strings/

// Time Complexity :- O(high)
// Space Complexity :- O(high)

// Solved by Memoization Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int index, int zero, int one, vector<int> &dp)
    {
        if (index == 0)
            return 1;

        if (dp[index] != -1)
            return dp[index];

        int count = 0;

        if (index >= zero)
            count += solve(index - zero, zero, one, dp);

        if (index >= one)
            count += solve(index - one, zero, one, dp);

        dp[index] = count % MOD;

        return dp[index];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp (high + 1, -1);
        
        int count = 0;

        for (int it = low; it <= high; it++)
        {
            count += solve(it, zero, one, dp);
            count %= MOD;
        }

        return count;
    }
};


// Solved by Tabulation Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp (high + 1, 0);
        dp[0] = 1;

        for (int index = 1; index <= high; index++)
        {
            if (index >= zero)
                dp[index] += dp[index - zero];

            if (index >= one)
                dp[index] += dp[index - one];

            dp[index] %= MOD;
        }

        int count = 0;

        for (int it = low; it <= high; it++)
        {
            count += dp[it];
            count %= MOD;
        }

        return count;
    }
};