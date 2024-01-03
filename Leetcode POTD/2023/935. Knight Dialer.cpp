// Problem Link :- https://leetcode.com/problems/knight-dialer/

// Solved by Memoization Method
// Time Complexity :- O(10 * n)
// Space Complexity :- O(10 * n)

class Solution {
public:

    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int solve (int steps, int cell, vector<vector<int>> &dp)
    {
        if (steps == 0)
            return 1;

        if (dp[steps][cell] != -1)
            return dp[steps][cell];

        long count = 0;

        for (auto &nextCell : jumps[cell])
        {
            count += solve(steps - 1, nextCell, dp);
            count %= MOD;
        }

        return dp[steps][cell] = count;
    }

    int knightDialer(int n) {
        
        vector<vector<int>> dp(n, vector<int> (10, -1));
        long ans = 0;

        for (int cell = 0; cell < 10; cell++)
        {
            ans += solve(n - 1, cell, dp);
            ans %= MOD;
        }

        return ans;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(10 * n)
// Space Complexity :- O(10 * n)

class Solution {
public:

    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int knightDialer(int n) {

        vector<vector<int>> dp(n, vector<int> (10, 0));

        for (int cell = 0; cell < 10; cell++)
            dp[0][cell] = 1;

        for (int steps = 1; steps < n; steps++)
        {
            for (int cell = 0; cell < 10; cell++)
            {
                for (auto &nextCell : jumps[cell])
                {
                    dp[steps][cell] += dp[steps - 1][nextCell];
                    dp[steps][cell] %= MOD;
                }
            }
        }

        long ans = 0;

        for (int cell = 0; cell < 10; cell++)
        {
            ans += dp[n - 1][cell];
            ans %= MOD;
        }

        return ans;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(10 * n)
// Space Complexity :- O(10)

class Solution {
public:

    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int knightDialer(int n) {

        vector<int> dp(10, 1);

        for (int steps = 1; steps < n; steps++)
        {
            vector<int> temp(10, 0);

            for (int cell = 0; cell < 10; cell++)
            {
                for (auto &nextCell : jumps[cell])
                {
                    temp[cell] += dp[nextCell];
                    temp[cell] %= MOD;
                }
            }

            dp = temp;
        }

        long ans = 0;

        for (int cell = 0; cell < 10; cell++)
        {
            ans += dp[cell];
            ans %= MOD;
        }

        return ans;
    }
};