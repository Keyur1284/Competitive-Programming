// Problem Link :- https://leetcode.com/problems/perfect-squares/

// Solved by Memoization Method
// Time Complexity :- O(n * sqrt(n))
// Space Complexity :- O(n)

class Solution {
public:
    
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        
        if (dp[n] != -1)
            return dp[n];
        
        int ans = 1e9;
        
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve(n - i * i, dp));
        }
        
        return dp[n] = ans;
    }

    int numSquares(int n) {

        vector<int> dp (n + 1, -1);
        return solve(n, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * sqrt(n))
// Space Complexity :- O(n)

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp (n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};