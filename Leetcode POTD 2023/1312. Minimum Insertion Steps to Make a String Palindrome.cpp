// Problem Link :- https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

// Solved by Memoization Method

class Solution {
public:

    int func (int i, int j, vector<vector<int>> &dp, string &s)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = func (i + 1, j - 1, dp, s);

        else
            return dp[i][j] = 1 + min(func(i + 1, j, dp, s), func(i, j - 1, dp, s));
    }

    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));

        return func (0, n - 1, dp, s);
    }
};


//Solved by Memoization Method  (Shifting of index to right by 1)

class Solution {
public:

    int func (int i, int j, vector<vector<int>> &dp, string &s)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == s[j - 1])
            return dp[i][j] = func (i + 1, j - 1, dp, s);

        else
            return dp[i][j] = 1 + min(func(i + 1, j, dp, s), func(i, j - 1, dp, s));
    }

    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));

        return func (1, n, dp, s);
    }
};


// Solved by Tabulation Method (Shifting of index to right by 1)

class Solution {
public:

    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp (n + 2, vector<int> (n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if (s[i - 1] == s[j - 1])
                    dp[i][j] = dp[i + 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[1][n];
    }
};


// Solved by Tabulation Method (Space Optimized)

class Solution {
public:

    int minInsertions(string s) {
        
        int n = s.size();
        vector<int> dp (n + 1, 0);

        for (int i = n; i >= 1; i--)
        {
            vector<int> temp (n + 1, 0);

            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                {
                    temp[j] = 0;
                    continue;
                }

                if (s[i - 1] == s[j - 1])
                    temp[j] = dp[j - 1];

                else
                    temp[j] = 1 + min(temp[j - 1], dp[j]);
            }

            dp = temp;
        }

        return dp[n];
    }
};