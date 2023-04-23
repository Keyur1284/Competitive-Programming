// Problem Link :- https://leetcode.com/problems/restore-the-array/

// Time Complexity :- O(n*log_10k)
// Space Complexity :- O(n)

// Solved by Memoization Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int DFS (int start, vector<int> &dp, string &s, int n, int k)
    {
        if (start == n)
            return 1;

        if (dp[start] != -1)
            return dp[start];

        if (s[start] == '0')
            return 0;

        int count = 0;
        long long num = 0;
        for (int end = start; end < n; end++)
        {
            num = num * 10 + s[end] - '0';

            if (num <= k)
            {
                count += DFS (end + 1, dp, s, n, k);
                count %= MOD;
            }

            else
                break;
        }

        return dp[start] = count;
    }

    int numberOfArrays(string s, int k) {
        
        int n = s.size();
        vector<int> dp(n, -1);

        return DFS (0, dp, s, n, k);
    }
};


// Solved by Tabulation Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int start = n - 1; start >= 0; start--)
        {
            if (s[start] == '0')
            {
                dp[start] = 0;
                continue;
            }

            int count = 0;
            long long num = 0;

            for (int end = start; end < n; end++)
            {
                num = num * 10 + s[end] - '0';

                if (num <= k)
                {
                    count += dp[end + 1];
                    count %= MOD;
                }

                else
                    break;
            }

            dp[start] = count;
        } 

        return dp[0];
    }
};

class Solution {
public:

    int MOD = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int start = 0; start < n; start++)
        {
            if (s[start] == '0')
            {
                dp[start] = 0;
                continue;
            }

            long long num = 0;

            for (int end = start; end < n; end++)
            {
                num = num * 10 + s[end] - '0';

                if (num <= k)
                {
                    dp[end + 1] += dp[start];
                    dp[end + 1] %= MOD;
                }

                else
                    break;
            }
        } 

        return dp[n];
    }
};


// Solved by Tabulation Method (Space Optimized)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numberOfArrays(string s, int k) {
        
        int n = s.size();
        int m = log10(k) + 1;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int start = 0; start < n; start++)
        {
            if (s[start] == '0')
            {
                dp[start % (m + 1)] = 0;
                continue;
            }

            long long num = 0;

            for (int end = start; end < n; end++)
            {
                num = num * 10 + s[end] - '0';

                if (num <= k)
                {
                    dp[(end + 1) % (m + 1)] += dp[start % (m + 1)];
                    dp[(end + 1) % (m + 1)] %= MOD;
                }

                else
                    break;
            }

            dp[start % (m + 1)] = 0;
        } 

        return dp[n % (m + 1)];
    }
};