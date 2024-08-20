// Problem Link :- https://leetcode.com/problems/2-keys-keyboard/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int solve (int currLen, int pasteLen, int n, vector<vector<int>> &dp)
    {
        if (currLen >= n)
            return (currLen == n) ? 0 : 1e9;

        if (dp[currLen][pasteLen] != -1)
            return dp[currLen][pasteLen];

        int paste = 1 + solve(currLen + pasteLen, pasteLen, n, dp);
        int copyPaste = 2 + solve(currLen + currLen, currLen, n, dp);

        return dp[currLen][pasteLen] = min(paste, copyPaste);
    }
    
    int minSteps(int n) {
        
        if (n == 1) 
            return 0;

        vector<vector<int>> dp (n + 1, vector<int> (n/2 + 1, -1));
        return 1 + solve(1, 1, n, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    
    int minSteps(int n) {
        
        if (n == 1) 
            return 0;

        vector<vector<int>> dp (n + 1, vector<int> (n/2 + 1, 1e9));
        
        for (int i = 0; i <= n/2; i++)
            dp[n][i] = 0;

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = 1; j <= n/2; j++)
            {
                int paste = 1e9, copyPaste = 1e9;

                if (i + j <= n)
                    paste = 1 + dp[i + j][j];

                if (i + i <= n)
                    copyPaste = 2 + dp[i + i][i];

                dp[i][j] = min(paste, copyPaste);
            }
        }

        return 1 + dp[1][1];
    }
};




// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int minSteps(int n) {
        
        vector<int> dp(n + 1, 1000);
        dp[1] = 0;

        for (int i = 2; i <= n; i++) 
        {
            for (int j = 1; j <= i / 2; j++) 
            {
                if (i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }

        return dp[n];
    }
};



// Solved by Maths
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minSteps(int n) {
        
        int steps = 0, primeFactor = 2;

        while (n > 1) 
        {
            while (n % primeFactor == 0) 
            {
                steps += primeFactor;
                n /= primeFactor;
            }

            primeFactor++;
        }
        
        return steps;
    }
};