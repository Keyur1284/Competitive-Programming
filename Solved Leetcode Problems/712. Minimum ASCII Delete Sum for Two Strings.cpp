// Problem Link :- https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

// Solved by Memoization Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int sumAscii (string &s, int n)
    {
        int sum = 0;

        for (int i = 1; i <= n; i++)
            sum += (int)s[i - 1];

        return sum;
    }

    int func (int i, int j, vector<vector<int>> &dp, string &s1, string &s2)
    {
        if (i == 0)
            return sumAscii (s2, j);

        if (j == 0)
            return sumAscii (s1, i);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = func (i - 1, j - 1, dp, s1, s2);

        int first = (int)s1[i - 1] + func (i - 1, j, dp, s1, s2);
        int second = (int)s2[j - 1] + func (i, j - 1, dp, s1, s2);

        return dp[i][j] = min (first, second);
    }

    int minimumDeleteSum(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));

        return func (n, m, dp, s1, s2);
    }
};



// Solved by Tabultion Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int minimumDeleteSum(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        int sumi = 0;

        for (int i = 0; i <= n; i++)
        {
            int sumj = 0;

            if (i > 0)
                sumi += (int)s1[i - 1];

            for (int j = 0; j <= m; j++)
            {
                if (j > 0)
                    sumj += (int)s2[j - 1];

                if (i == 0)
                    dp[i][j] = sumj;

                else if (j == 0)
                    dp[i][j] = sumi;

                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                {
                    int first = (int)s1[i - 1] + dp[i - 1][j];
                    int second = (int)s2[j - 1] + dp[i][j - 1];

                    dp[i][j] = min(first, second);
                }
            }
        }

        return dp[n][m];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * m)
// Space Complexity :- O(m)

class Solution {
public:

    int minimumDeleteSum(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<int> dp (m + 1, 0);
        int sumi = 0;

        for (int i = 0; i <= n; i++)
        {
            int sumj = 0;

            if (i > 0)
                sumi += (int)s1[i - 1];

            vector<int> temp (m + 1, 0);

            for (int j = 0; j <= m; j++)
            {
                if (j > 0)
                    sumj += (int)s2[j - 1];

                if (i == 0)
                    temp[j] = sumj;

                else if (j == 0)
                    temp[j] = sumi;

                else if (s1[i - 1] == s2[j - 1])
                    temp[j] = dp[j - 1];

                else
                {
                    int first = (int)s1[i - 1] + dp[j];
                    int second = (int)s2[j - 1] + temp[j - 1];

                    temp[j] = min(first, second);
                }
            }

            dp = temp;
        }

        return dp[m];
    }
};