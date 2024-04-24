// Problem Link :- https://leetcode.com/problems/n-th-tribonacci-number/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    
    int solve(int n,vector<int> &dp)
    {
        if (n == 0) 
            return 0;
        if (n <= 2) 
            return 1;

        if (dp[n] != -1) 
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
    }
    
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int tribonacci(int n) {
        
        vector<int> Tribonacci (n + 3, 0);
        Tribonacci[1] = 1;
        Tribonacci[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            Tribonacci[i] = Tribonacci[i - 1] + Tribonacci[i - 2] + Tribonacci[i - 3];
        }

        return Tribonacci[n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int tribonacci(int n) {
        
        vector<int> dp = {0, 1, 1};

        for (int i = 3; i <= n; i++)
        {
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        }

        return dp[n%3];
    }
};



class Solution {
public:

    int tribonacci(int n) {
        
        if (n == 0)
            return 0;

        if (n <= 2)
            return 1;

        int temp0 = 0, temp1 = 1, temp2 = 1, ans;

        for (int i = 3; i <= n; i++)
        {
            ans = temp0 + temp1 + temp2;
            temp0 = temp1;
            temp1 = temp2;
            temp2 = ans;
        }

        return ans;
    }
};