// Problem Link :- https://leetcode.com/problems/longest-palindromic-subsequence/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

//Solved by Memoization Method

class Solution {
public:

    int func (int i, int j, vector<vector<int>> &dp, string &s)
    {
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            dp[i][j] = 2 + func (i + 1, j - 1, dp, s);

        else
            dp[i][j] = max(func(i + 1, j, dp, s), func(i, j - 1, dp, s));

            return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return func (0, n - 1, dp, s);
    }
};

class Solution {
public:

    int func (int i, int j, vector<vector<int>> &dp, string &s, string &t)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            dp[i][j] = 1 + func (i - 1, j - 1, dp, s, t);

        else
            dp[i][j] = max(func(i - 1, j, dp, s, t), func(i, j - 1, dp, s, t));

            return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        string t = s;
        reverse(t.begin(), t.end());

        return func (n - 1, n - 1, dp, s, t);
    }
};


//Solved by Memoization Method  (Shifting of index to right by 1)

class Solution {
public:

    int func (int i, int j, vector<vector<int>> &dp, string &s, string &t)
    {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
            dp[i][j] = 1 + func (i - 1, j - 1, dp, s, t);

        else
            dp[i][j] = max(func(i - 1, j, dp, s, t), func(i, j - 1, dp, s, t));

            return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        string t = s;
        reverse(t.begin(), t.end());

        return func (n, n, dp, s, t);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];

                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};

//Solved by Tabulation Method (Shifting of index to right by 1)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        string t = s;
        reverse(t.begin(), t.end());

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};


//Solved by Tabulation Method (Space Optimized)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp(n, 0);
            temp[i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    temp[j] = 2 + dp[j - 1];

                else
                    temp[j] = max(dp[j], temp[j - 1]);
            }

            dp = temp;
        }

        return dp[n - 1];
    }
};

//Solved by Tabulation Method (Space Optimized) (Shifting of index to right by 1)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<int> dp(n + 1, 0);

        string t = s;
        reverse(t.begin(), t.end());

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(n + 1, 0);

            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    temp[j] = 1 + dp[j - 1];

                else
                    temp[j] = max(dp[j], temp[j - 1]);
            }

            dp = temp;
        }

        return dp[n];
    }
};

