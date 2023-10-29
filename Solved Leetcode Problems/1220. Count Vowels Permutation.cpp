// Problem Link :- https://leetcode.com/problems/count-vowels-permutation/

// Solved by Memoization Method
// Time Complexity :- O(5 * n)
// Space Complexity :- O(5 * n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int n, int prev, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n][prev + 1] != -1)
            return dp[n][prev + 1];

        long long ways = 0;

        if (prev == -1)
        {
            ways = (ways + 1 + solve(n - 1, 0, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 1, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 2, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 3, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 4, dp)) % MOD;
        }

        if (prev == 0)
        {
            ways = (ways + 1 + solve(n - 1, 1, dp)) % MOD;
        }

        if (prev == 1)
        {
            ways = (ways + 1 + solve(n - 1, 0, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 2, dp)) % MOD;
        }

        if (prev == 2)
        {
            ways = (ways + 1 + solve(n - 1, 0, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 1, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 3, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 4, dp)) % MOD;
        }

        if (prev == 3)
        {
            ways = (ways + 1 + solve(n - 1, 2, dp)) % MOD;
            ways = (ways + 1 + solve(n - 1, 4, dp)) % MOD;
        }

        if (prev == 4)
        {
            ways = (ways + 1 + solve(n - 1, 0, dp)) % MOD;
        }

        return dp[n][prev + 1] = ways % MOD;
    }

    int countVowelPermutation(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int> (6, -1));
        return (solve (n, -1, dp) - solve(n - 1, -1, dp) + MOD) % MOD;
    }
};



class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int n, int prev, vector<vector<int>> &dp)
    {
        if (n == 1)
            return 1;

        if (dp[n][prev] != -1)
            return dp[n][prev];

        long long ways = 0;

        if (prev == 0)
        {
            ways = (ways + solve(n - 1, 1, dp)) % MOD;
        }

        if (prev == 1)
        {
            ways = (ways + solve(n - 1, 0, dp)) % MOD;
            ways = (ways + solve(n - 1, 2, dp)) % MOD;
        }

        if (prev == 2)
        {
            ways = (ways + solve(n - 1, 0, dp)) % MOD;
            ways = (ways + solve(n - 1, 1, dp)) % MOD;
            ways = (ways + solve(n - 1, 3, dp)) % MOD;
            ways = (ways + solve(n - 1, 4, dp)) % MOD;
        }

        if (prev == 3)
        {
            ways = (ways + solve(n - 1, 2, dp)) % MOD;
            ways = (ways + solve(n - 1, 4, dp)) % MOD;
        }

        if (prev == 4)
        {
            ways = (ways + solve(n - 1, 0, dp)) % MOD;
        }

        return dp[n][prev] = ways % MOD;
    }

    int countVowelPermutation(int n) {
        
        vector<vector<int>> dp(n + 1, vector<int> (5, -1));
        long long ans = 0;

        for (int i = 0; i < 5; i++)
        {
            ans += solve(n, i, dp);
            ans %= MOD;
        }

        return ans;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(5 * n)
// Space Complexity :- O(5 * n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countVowelPermutation(int n) {
        
        vector<vector<long>> dp(n + 1, vector<long> (5, 0));

        for (int i = 0; i < 5; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = (dp[i - 1][2]) % MOD;
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < 5; i++)
        {
            ans += dp[n][i];
            ans %= MOD;
        }

        return ans;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(5 * n)
// Space Complexity :- O(5)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countVowelPermutation(int n) {
        
        vector<long> dp(5, 1);

        for (int j = 2; j <= n; j++)
        {
            long a = (dp[1] + dp[2] + dp[4]) % MOD;
            long e = (dp[0] + dp[2]) % MOD;
            long i = (dp[1] + dp[3]) % MOD;
            long o = (dp[2]) % MOD;
            long u = (dp[2] + dp[3]) % MOD;

            dp[0] = a;
            dp[1] = e;
            dp[2] = i;
            dp[3] = o;
            dp[4] = u;
        }

        long long ans = 0;

        for (int i = 0; i < 5; i++)
        {
            ans += dp[i];
            ans %= MOD;
        }

        return ans;
    }
};



class Solution {
public:
    int countVowelPermutation(int n) {
        
        int MOD = 1e9 + 7;
        
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        
        for (int j = 1; j < n; j++) 
        {
            long long a_next = e;
            long long e_next = (a + i) % MOD;
            long long i_next = (a + e + o + u) % MOD;
            long long o_next = (i + u) % MOD;
            long long u_next = a;
            
            a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;
        }
        
        return (a + e + i + o + u) % MOD;
    }
};