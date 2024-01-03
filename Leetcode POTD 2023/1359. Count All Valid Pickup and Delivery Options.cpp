// Problem Link :- https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int unpicked, int undelivered, vector<vector<int>> &dp)
    {
        if (unpicked == 0 && undelivered == 0)
            return 1;

        if (unpicked < 0 || undelivered < 0 || unpicked > undelivered)
            return 0;

        if (dp[unpicked][undelivered] != -1)
            return dp[unpicked][undelivered];

        long pickup = 1LL * unpicked * solve(unpicked - 1, undelivered, dp);
        pickup %= MOD;

        long delivery = 1LL * (undelivered - unpicked) * solve(unpicked, undelivered - 1, dp);
        delivery %= MOD;

        return dp[unpicked][undelivered] = 1LL * (pickup + delivery) % MOD;
    }

    int countOrders(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(n, n, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countOrders(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;

        for (int undelivered = 1; undelivered <= n; undelivered++)
        {
            for (int unpicked = 0; unpicked <= undelivered; unpicked++)
            {
                long pickup = 0;

                if (unpicked >= 1)
                {
                    pickup = 1LL * unpicked * dp[unpicked - 1][undelivered];
                    pickup %= MOD;
                }

                long delivery = 1LL * (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                delivery %= MOD;

                dp[unpicked][undelivered] = 1LL * (pickup + delivery) % MOD;
            }
        }

        return dp[n][n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countOrders(int n) {
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int undelivered = 1; undelivered <= n; undelivered++)
        {
            vector<int> temp(n + 1, 0);

            for (int unpicked = 0; unpicked <= undelivered; unpicked++)
            {
                long pickup = 0;

                if (unpicked >= 1)
                {
                    pickup = 1LL * unpicked * temp[unpicked - 1];
                    pickup %= MOD;
                }

                long delivery = 1LL * (undelivered - unpicked) * dp[unpicked];
                delivery %= MOD;

                temp[unpicked] = 1LL * (pickup + delivery) % MOD;
            }

            dp = temp;
        }

        return dp[n];
    }
};



// Solved by Math + Combinatorics
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countOrders(int n) {
        
        int ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans = (1LL * ans * (2 * i - 1) * i) % MOD;
        }

        return ans;
    }
};