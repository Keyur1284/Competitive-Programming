//Problem Link :-  https://leetcode.com/problems/distinct-subsequences/


//Solved by Memoization Method

class Solution {
public:
    int func (int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (j < 0)
            return 1;
        
        if (i < 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i] == t[j])
            return dp[i][j] = func (i - 1, j, s, t, dp) + func (i - 1, j - 1, s, t, dp);
        
        else
            return dp[i][j] = func (i - 1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<int>> dp (n, vector <int> (m, -1));
        
        return func (n - 1, m - 1, s, t, dp);
    }
};


//Solved by Memoization Method (Shifting of index to right by 1)

class Solution {
public:
    int func (int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (j == 0)
            return 1;
        
        if (i == 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = func (i - 1, j, s, t, dp) + func (i - 1, j - 1, s, t, dp);
        
        else
            return dp[i][j] = func (i - 1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<int>> dp (n + 1, vector <int> (m + 1, -1));
        
        return func (n, m, s, t, dp);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    int func (int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (j == 0)
            return 1;
        
        if (i == 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = func (i - 1, j, s, t, dp) + func (i - 1, j - 1, s, t, dp);
        
        else
            return dp[i][j] = func (i - 1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<double>> dp (n + 1, vector <double> (m + 1, 0));
        
        for (int i = 0; i<=n; i++)
            dp[i][0] = 1;
        
        for (int j = 1; j<=m; j++)      //Start j from 1 because we dont't want to rewrite dp[0][0]
            dp[0][j] = 0;
        
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return (int)dp[n][m];
    }
};


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)

class Solution {
public:
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <double> dp (m + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i<=n; i++)
        {
            vector <double> temp (m + 1, 0);
            temp[0] = 1;
            
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    temp[j] = dp[j] + dp[j - 1];
                
                else
                    temp[j] = dp[j];
            }
            
            dp = temp;
        }
        
        return (int)dp[m];
    }
};


//Solved by Tabulation Method (Best Space Optimized) (Using 1D array only)

class Solution {
public:
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <double> dp (m + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i<=n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j] + dp[j - 1];
                
                else
                    dp[j] = dp[j];     
            }
        }
        
        return (int)dp[m];
    }
};