//Problem Link :- https://leetcode.com/problems/edit-distance/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int i, int j, string &s, string &t, vector <vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        
        if (j < 0)
            return i + 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i] == t[j])
            return dp[i][j] = func (i - 1, j - 1, s, t, dp);
        
        int insert = 1 + func (i, j - 1, s, t, dp);
        int replace = 1 + func (i - 1, j - 1, s, t, dp);
        int del = 1 + func (i - 1, j, s, t, dp);
        
        return dp[i][j] = min (del, min (replace, insert));
    }
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<int>> dp(n, vector <int> (m, -1));
        
        return func (n - 1, m - 1, s, t, dp);
    }
};


//Solved by Memoization Method (Shifting of index to right by 1)

class Solution {
public:
    
    int func (int i, int j, string &s, string &t, vector <vector<int>> &dp)
    {
        if (i == 0)
            return j;
        
        if (j == 0)
            return i;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = func (i - 1, j - 1, s, t, dp);
        
        int insert = 1 + func (i, j - 1, s, t, dp);
        int replace = 1 + func (i - 1, j - 1, s, t, dp);
        int del = 1 + func (i - 1, j, s, t, dp);
        
        return dp[i][j] = min (del, min (replace, insert));
    }
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<int>> dp(n + 1, vector <int> (m + 1, -1));
        
        return func (n, m, s, t, dp);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector<int>> dp(n + 1, vector <int> (m + 1, 0));
        
        for (int j = 0; j<=m; j++)
            dp[0][j] = j;
        
        for (int i = 0; i<=n; i++)
            dp[i][0] = i;
        
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                else
                {
                    int insert = 1 + dp[i][j - 1];
                    int replace = 1 + dp[i - 1][j - 1];
                    int del = 1 + dp[i - 1][j];
                    
                    dp[i][j] = min (del, min (replace, insert));
                }
            }
        }
        
        return dp[n][m];
    }
};


//Solved by Tabulation Method (Less space optimized) (Using 2 rows)

class Solution {
public:
    
    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<int> dp(m + 1, 0);
        
        for (int j = 0; j<=m; j++)
            dp[j] = j;
        
        for (int i = 1; i<=n; i++)
        {
            vector <int> temp (m + 1, 0);
            temp[0] = i;
            
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    temp[j] = dp[j - 1];
                
                else
                {
                    int insert = 1 + temp[j - 1];
                    int replace = 1 + dp[j - 1];
                    int del = 1 + dp[j];
                    
                    temp[j] = min (del, min (replace, insert));
                }
            }
            
            dp = temp;
        }
        
        return dp[m];
    }
};


//Solved by Tabulation Method (Best space optimized) (Using 1D Array only)
//Very Important : Just by using two variables and one 1D Array, we can solve this

class Solution {
public:

    int minDistance(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector<int> dp(m + 1, 0);
        
        for (int j = 0; j<=m; j++)
            dp[j] = j;
        
        int first;
        
        for (int i = 1; i<=n; i++)
        {
            first = dp[0];
            dp[0] = i;
            
            for (int j = 1; j<=m; j++)
            {
                int temp = dp[j];
                
                if (s[i - 1] == t[j - 1])
                    dp[j] = first;
                
                else
                {
                    int insert = 1 + first;
                    int replace = 1 + dp[j - 1];
                    int del = 1 + dp[j];
                    
                    dp[j] = min (del, min (replace, insert));
                }
                
                first = temp;
            }
        }
        
        return dp[m];
    }
};