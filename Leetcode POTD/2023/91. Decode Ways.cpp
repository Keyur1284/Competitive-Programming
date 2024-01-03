// Problem Link :- https://leetcode.com/problems/decode-ways/

// Solved by Memoization Method
// Time Complexity :- O(n) 
// Space Complexity :- O(n)

class Solution {
public:
    
    int solve (int index, int &n, vector<int> &dp, string &s)
    {
        if (index == n)
            return 1;

        if (dp[index] != -1)
            return dp[index];

        if (s[index] == '0')
            return dp[index] = 0;

        int takeone = 0, taketwo = 0;
        
        takeone += solve (index + 1, n, dp, s);

        if (index + 1 < n && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
        {
            taketwo += solve (index + 2, n, dp, s);
        }

        return dp[index] = takeone + taketwo;
    }

    int numDecodings(string &s) {
        
        int n = s.length();
        vector<int> dp (n, -1);

        return solve (0, n, dp, s);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    
    int numDecodings(string &s) {
        
        int n = s.length();
        vector<int> dp (n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                dp[i] = 0;

            else
            {
                dp[i] += dp[i + 1];

                if (i + 1 < n && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    
    int numDecodings(string &s) {
        
        int n = s.length(), dp1 = 1, dp2 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int dp = 0;

            if (s[i] != '0')
            {
                dp += dp1;

                if (i + 1 < n && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                {
                    dp += dp2;
                }
            }

            dp2 = dp1;
            dp1 = dp;
        }

        return dp1;
    }
};