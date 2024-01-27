// Problem Link :- https://leetcode.com/problems/k-inverse-pairs-array/

// Solved by Brute Force Method (TLE)
// Time Complexity :- O(n * k * min(n, k))
// Space Complexity :- O(n * k)

class Solution {
public:


    int kInversePairs(int n, int k) {
        
        int MOD = 1e9 + 7;
        int dp[n + 1][k + 1];

        memset(dp, -1, sizeof(dp));

        auto solve = [&](auto self, int n, int k)
        {
            if (n == 0)
                return 0;

            if (k == 0)
                return 1;

            if (dp[n][k] != -1)
                return dp[n][k];

            long perms = 0;

            for (int i = 0; i <= min(k, n - 1); i++)
            {
                perms += self(self, n - 1, k - i) % MOD;
                perms %= MOD;
            }

            return dp[n][k] = perms;
        };

        return solve(solve, n, k);
    }
};



// Solved by Memoization Method
// Time Complexity :- O(n * k)
// Space Complexity :- O(n * k)

class Solution {
public:

    int kInversePairs(int n, int k) {
        
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));

        auto solve = [&](auto self, int n, int k)
        {
            if (k == 0)
                return 1;

            if (n == 0)
                return 0;

            if (dp[n][k] != -1)
                return dp[n][k];

            long perms = (self(self, n, k - 1) + self(self, n - 1, k)) % MOD;

            if (k >= n)
                perms = (perms - self(self, n - 1, k - n) + MOD) % MOD;

            return dp[n][k] = perms;
        };

        return solve(solve, n, k);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * k)
// Space Complexity :- O(n * k)

class Solution {
public:

    int kInversePairs(int n, int k) {
        
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;

                if (j >= i)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * k)
// Space Complexity :- O(k)

class Solution {
public:

    int kInversePairs(int n, int k) {
        
        int MOD = 1e9 + 7;
        vector<int> dp(k + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(k + 1, 0);
            temp[0] = 1;

            for (int j = 1; j <= k; j++)
            {
                temp[j] = (temp[j - 1] + dp[j]) % MOD;

                if (j >= i)
                    temp[j] = (temp[j] - dp[j - i] + MOD) % MOD;
            }
            
            dp = temp;
        }

        return dp[k];
    }
};