// Problem Link :- https://leetcode.com/problems/wildcard-matching/

//Solved by Memoization Method 
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:
    
    bool isAllStars (string &p, int i)
    {
        for (int k = 0; k <= i; k++)
            if (p[k] != '*')
                return false;
        
        return true;
    }
    
    bool func (int i, int j, string &s, string &p, vector <vector <int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        
        if (j < 0 && i >= 0)
            return false;
        
        if (i < 0 && j >= 0)
            return isAllStars(p, j);
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = func (i - 1, j - 1, s, p, dp);
        
        if (p[j] == '*')
            return dp[i][j] = func (i - 1, j, s, p, dp) || func (i, j - 1, s, p, dp); 

        return false;       
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        vector <vector <int>> dp (n, vector <int> (m, -1));
        
        return func (n - 1, m - 1, s, p, dp);
        
    }
};



//Solved by Memoization Method (Shifting of index to right by 1)

class Solution {
public:
    
    bool isAllStars (string &p, int i)
    {
        for (int k = 1; k <= i; k++)
            if (p[k - 1] != '*')
                return false;
        
        return true;
    }
    
    bool func (int i, int j, string &s, string &p, vector <vector <int>> &dp)
    {
        if (i == 0 && j == 0)
            return true;
        
        if (j == 0 && i > 0)
            return false;
        
        if (i == 0 && j > 0)
            return isAllStars(p, j);
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = func (i - 1, j - 1, s, p, dp);
        
        if (p[j - 1] == '*')
            return dp[i][j] = func (i - 1, j, s, p, dp) || func (i, j - 1, s, p, dp); 

        return false;       
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        vector <vector <int>> dp (n + 1, vector <int> (m + 1, -1));
        
        return func (n, m, s, p, dp);
        
    }
};


//Solved by Tabulation Method (Shifting of index to right by 1)

class Solution {
public:
    
    bool isAllStars (string &p, int i)
    {
        for (int k = 1; k <= i; k++)
            if (p[k - 1] != '*')
                return false;
        
        return true;
    }
 
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();

        vector <vector <bool>> dp (n + 1, vector <bool> (m + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        
        for (int j = 1; j <= m; j++)
            dp[0][j] = isAllStars(p, j);
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                    
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
        
    }
};