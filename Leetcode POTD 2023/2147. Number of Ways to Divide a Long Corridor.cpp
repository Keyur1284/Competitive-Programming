// Problem Link :- https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

// Solved by Memoization Method
// Time Complexity :- O(3 * n)
// Space Complexity :- O(3 * n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (int index, int seats, string &s, vector<vector<int>> &dp)
    {
        if (index == -1)
            return (seats == 2);

        if (dp[index][seats] != -1)
            return dp[index][seats];

        int count = 0;
        
        if (seats == 2)
        {
            count = solve(index - 1, (s[index] == 'S'), s, dp) % MOD;

            if (s[index] != 'S')
            {
                count += solve(index - 1, 2, s, dp);
                count %= MOD;
            }
        }

        else
        {
            count = solve(index - 1, seats + (s[index] == 'S'), s, dp) % MOD;
        }
        
        return dp[index][seats] = count;
    }

    int numberOfWays(string corridor) {
        
        int n = corridor.length();
        vector<vector<int>> dp (n, vector<int> (3, -1));

        return solve(n - 1, 0, corridor, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(3 * n)
// Space Complexity :- O(3 * n)

class Solution {
public:

    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        
        int n = corridor.length();
        vector<vector<int>> dp (n + 1, vector<int> (3, 0));
        dp[n][2] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (corridor[i] == 'S')
            {
                dp[i][0] = dp[i + 1][1];
                dp[i][1] = dp[i + 1][2];
                dp[i][2] = dp[i + 1][1];
            }

            else
            {
                dp[i][0] = dp[i + 1][0];
                dp[i][1] = dp[i + 1][1];
                dp[i][2] = (dp[i + 1][0] + dp[i + 1][2]) % MOD;
            }
        }

        return dp[0][0];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(3 * n)
// Space Complexity :- O(3)

class Solution {
public:

    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        
        int n = corridor.length();
        vector<int> dp (3, 0);
        dp[2] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(3, 0);

            if (corridor[i] == 'S')
            {
                temp[0] = dp[1];
                temp[1] = dp[2];
                temp[2] = dp[1];
            }

            else
            {
                temp[0] = dp[0];
                temp[1] = dp[1];
                temp[2] = (dp[0] + dp[2]) % MOD;
            }

            dp = temp;
        }

        return dp[0];
    }
};



class Solution {
public:

    int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        
        int n = corridor.length(), zero = 0, one = 0, two = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (corridor[i] == 'S')
            {
                zero = one;
                swap(one, two);
            }

            else
            {
                two = (zero + two) % MOD;
            }
        }

        return zero;
    }
};



// Solved by Combinatorics
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numberOfWays(string corridor) {
        
        int n = corridor.length();
        vector<int> pos;

        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
                pos.emplace_back(i);
        }

        int seats = pos.size();

        if (seats == 0 || seats & 1)
            return 0;

        long ways = 1;
        int prev = 1, curr = 2;

        while (curr < seats)
        {
            ways *= (pos[curr] - pos[prev]);
            ways %= MOD;

            prev += 2;
            curr += 2;
        }

        return ways;
    }
};



// Solved by Combinatorics (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numberOfWays(string corridor) {
        
        long ways = 1;
        int seats = 0, prevPos = -1, n = corridor.length();

        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
            {
                seats++;
                
                if (seats == 2)
                {
                    prevPos = i;
                    seats = 0;
                }

                else if (seats == 1 && prevPos != -1)
                {
                    ways *= (i - prevPos);
                    ways %= MOD;
                }
            }
        }

        if (seats == 1 || prevPos == -1)
            return 0;

        return ways;
    }
};