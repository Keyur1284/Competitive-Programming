// Problem Link :- https://leetcode.com/problems/longest-common-subsequence/

// Solved by Memoization Method
// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)

class Solution {
public:
    
    int func (int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] =  1 + func (i - 1, j - 1, s, t, dp);

        else
            return dp[i][j] = 0 + max (func (i - 1, j, s, t, dp), func (i, j - 1, s, t, dp));
    }
    
    int longestCommonSubsequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector <vector <int>> dp (n, vector <int> (m, -1));

        return func (n - 1, m - 1, s, t, dp);
    }
};



class Solution {
public:
    
    int func (int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] =  1 + func (i - 1, j - 1, s, t, dp);

        else
            return dp[i][j] = 0 + max (func (i - 1, j, s, t, dp), func (i, j - 1, s, t, dp));
    }
    
    int longestCommonSubsequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector <vector <int>> dp (n + 1, vector <int> (m + 1, -1));

        return func (n, m, s, t, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)

class Solution {
public:
    
    int longestCommonSubsequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector <vector <int>> dp (n + 1, vector <int> (m + 1, -1));

        for (int i = 0; i<=n; i++)
            dp[i][0] = 0;

        for (int j = 0; j<=m; j++)
            dp[0][j] = 0;

        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = 0 + max (dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];  
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n*m)
// Space Complexity :- O(m)

class Solution {
public:
    
    int longestCommonSubsequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector <int> dp(m + 1, 0);

        for (int j = 0; j<=m; j++)
            dp[j] = 0;

        for (int i = 1; i<=n; i++)
        {
            vector <int> temp (m + 1, 0);

            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    temp[j] = 1 + dp[j - 1];

                else
                    temp[j] = 0 + max (dp[j], temp[j - 1]);
            }

            dp = temp;
        }

        return dp[m];
    }
};