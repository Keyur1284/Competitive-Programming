// Problem Link :- https://leetcode.com/problems/integer-break/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int solve(int num, vector<int> &dp)
    {
        if (num <= 3)
            return num;

        if (dp[num] != -1)
            return dp[num];

        int maxProd = num;

        for (int i = 2; i < num; i++)
        {
            int prod = i * solve(num - i, dp);
            maxProd = max(prod, maxProd);
        }

        return dp[num] = maxProd;
    }

    int integerBreak(int n) {
        
        if (n <= 3)
            return n - 1;

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int integerBreak(int n) {
        
        if (n <= 3)
            return n - 1;

        vector<int> dp(n + 1, 0);

        for (int num = 0; num <= n; num++)
        {
            int maxProd = num;

            for (int i = 2; i < num; i++)
            {
                int prod = i * dp[num - i];
                maxProd = max(prod, maxProd);
            }

            dp[num] = maxProd;
        }

        return dp[n];
    }
};



// Solved by Maths
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int integerBreak(int n) {
        
        if (n <= 3)
            return n - 1;
        
        int ans = 1;

        while (n > 4)
        {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
};



// Solved by Equation
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int integerBreak(int n) {
        
        if (n <= 3)
            return n - 1;
        
        if (n % 3 == 0)
            return pow(3, n / 3);
        
        if (n % 3 == 1)
            return pow(3, n / 3 - 1) * 4;
        
        return pow(3, n / 3) * 2;
    }
};