// Problem Link :- https://leetcode.com/problems/number-of-music-playlists/

// Solved by Memoization Method
// Time Complexity :- O(n * goal)
// Space Complexity :- O(n * goal)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int songs, int goal, int n, int k, vector<vector<int>> &dp)
    {
        if (songs == 0 && goal == 0)
            return 1;

        if (songs == 0 || goal == 0)
            return 0;

        if (dp[songs][goal] != -1)
            return dp[songs][goal];

        long long ways = 1LL * solve(songs - 1, goal - 1, n, k, dp) * (n - songs + 1);
        ways %= MOD;

        if (songs > k)
        {
            ways += 1LL * solve(songs, goal - 1, n, k, dp) * (songs - k);
            ways %= MOD;
        }

        return dp[songs][goal] = ways;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int>> dp (n + 1, vector<int> (goal + 1, -1));

        return solve(n, goal, n, k, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * goal)
// Space Complexity :- O(n * goal)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<long>> dp (n + 1, vector<long> (goal + 1, 0));
        dp[0][0] = 1;

        for (int Goal = 1; Goal <= goal; Goal++)
        {
            for (int songs = 1; songs <= min(n, Goal); songs++)
            {
                dp[songs][Goal] = 1LL * dp[songs - 1][Goal - 1] * (n - songs + 1);
                dp[songs][Goal] %= MOD;

                if (songs > k)
                {
                    dp[songs][Goal] += 1LL * dp[songs][Goal - 1] * (songs - k);
                    dp[songs][Goal] %= MOD;
                }
            }
        }

        return dp[n][goal];
    }
};



// Solved by Binary Exponentiation + Combinatorics
// Time Complexity :- O(n * log(goal))
// Space Complexity :- O(n)

class Solution {
public:

    int MOD = 1e9 + 7;
    vector<long> fact, invFact;

    long long modPower (long long base, long long exp)
    {
        long long ans = 1;

        while (exp)
        {
            if (exp & 1)
                ans = (1LL * ans * base) % MOD;

            exp >>= 1;
            base = (1LL * base * base) % MOD;
        }

        return ans % MOD;
    }

    long long modInverse (long long num)
    {
        return modPower (num, MOD - 2);
    }

    void preCompute(int n)
    {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = invFact[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
            invFact[i] = modInverse (1LL * fact[i]);
        }
    }

    int numMusicPlaylists(int n, int goal, int k) {
        
        preCompute(n);
        int sign = 1;
        long long answer = 0;

        for (int songs = n; songs >= k; songs--, sign *= -1)
        {
            long long ways = modPower(1LL * (songs - k), 1LL * (goal - k));
            ways = (ways * invFact[n - songs]) % MOD;
            ways = (ways * invFact[songs - k]) % MOD;

            answer = (answer + ways * sign + MOD) % MOD;
        }

        return (1LL * fact[n] * answer) % MOD;
    }
};