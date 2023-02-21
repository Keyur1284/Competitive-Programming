//Problem Link :- https://leetcode.com/problems/climbing-stairs/

//Solved by Memoization Method

class Solution {
public:

    int func (int index, vector<int> &dp)
    {
        if (index <= 1)
            return 1;

        if (dp[index] != -1)
            return dp[index];

        return dp[index] = func(index - 1, dp) + func(index - 2, dp);
    }

    int climbStairs(int n) {

        vector <int> dp (n + 1, -1);

        return func(n, dp);

    }
};

//Solved by Tabulation Method

class Solution {
public:

    int climbStairs(int n) {

        vector <int> dp (n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int index = 2; index <= n; index++)
        {
            dp[index] = dp[index - 1] + dp[index - 2];
        }

        return dp[n];
    }
};

//Solved by Tabulation Method (Space Optimized)
class Solution {
public:

    int climbStairs(int n) {

        int prev2 = 1, prev = 1;

        for (int index = 2; index <= n; index++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};