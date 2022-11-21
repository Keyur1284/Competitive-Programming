//Problem Link: https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650

//Solved by Memoization Method 

#include <bits/stdc++.h>

bool isAllStars (string &s, int i)
{
    for (int k = 0; k<=i; k++)
        if (s[k] != '*')
            return false;

    return true;
}

bool func (int i, int j, string &s, string &p, vector <vector <int>> &dp)
{
    if (i < 0 && j < 0)
        return true;

    if (i < 0 && j >= 0)
        return false;

    if (j < 0 && i >= 0)
        return isAllStars(s, i);

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || s[i] == '?')
        return dp[i][j] = func (i - 1, j - 1, s, p, dp);

    if (s[i] == '*')
        return dp[i][j] = func (i - 1, j, s, p, dp) || func (i, j - 1, s, p, dp);

    return false;
}

bool wildcardMatching(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector <vector <int>> dp (n, vector <int> (m, -1));

    return func (n - 1, m - 1, s, p, dp);
}


//Solved by Memoization Method (Shifting of index to right by 1)

#include <bits/stdc++.h>

bool isAllStars (string &s, int i)
{
    for (int k = 1; k<=i; k++)
        if (s[k - 1] != '*')
            return false;

    return true;
}

bool func (int i, int j, string &s, string &p, vector <vector <int>> &dp)
{
    if (i == 0 && j == 0)
        return true;

    if (i == 0 && j > 0)
        return false;

    if (j == 0 && i > 0)
        return isAllStars(s, i);

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
        return dp[i][j] = func (i - 1, j - 1, s, p, dp);

    if (s[i - 1] == '*')
        return dp[i][j] = func (i - 1, j, s, p, dp) || func (i, j - 1, s, p, dp);

    return false;
}

bool wildcardMatching(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector <vector <int>> dp (n + 1, vector <int> (m + 1, -1));

    return func (n, m, s, p, dp);
}



//Solved by Tabulation Method

#include <bits/stdc++.h>

bool isAllStars (string &s, int i)
{
    for (int k = 1; k<=i; k++)
        if (s[k - 1] != '*')
            return false;

    return true;
}

bool wildcardMatching(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector <vector <bool>> dp (n + 1, vector <bool> (m + 1, false));
    dp[0][0] = true;
    
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    
    for (int i = 1; i<=n; i++)
        dp[i][0] = isAllStars(s, i);
    
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
                
            else if (s[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}


//Solved by Tabulation Method (Space Optimized)

#include <bits/stdc++.h>

bool isAllStars (string &s, int i)
{
    for (int k = 1; k<=i; k++)
        if (s[k - 1] != '*')
            return false;

    return true;
}

bool wildcardMatching(string s, string p)
{
    int n = s.size();
    int m = p.size();

    vector <bool> dp (m + 1, false);
    dp[0] = true;
    
    for (int j = 1; j <= m; j++)
        dp[j] = false;
    
    for (int i = 1; i<=n; i++)
    {
        vector <bool> temp (m + 1, false);
        temp[0] = isAllStars(s, i);
        
        for (int j = 1; j<=m; j++)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
                temp[j] = dp[j - 1];
                
            else if (s[i - 1] == '*')
                temp[j] = dp[j] | temp[j - 1];
            
            else
                temp[j] = false;
        }
        
        dp = temp;
    }

    return dp[m];
}
