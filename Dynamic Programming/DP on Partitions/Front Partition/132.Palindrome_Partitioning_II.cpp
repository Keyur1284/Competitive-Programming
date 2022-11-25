//Problem Link :- https://leetcode.com/problems/palindrome-partitioning-ii/

//Solved by Memoization Method

class Solution {
public:
    
    bool isPalindrome (string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int func (int i, int n, vector <int> &dp, string &s)
    {
        if (i == n)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int mini = INT_MAX;
        
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                int cost = 1 + func (j + 1, n, dp, s);
                mini = min (mini, cost);
            }
        }
        
        return dp[i] = mini;
    }
    
    int minCut(string s) {
        
        int n = s.size();
        vector <int> dp (n, -1);
        
        return func (0, n, dp, s) - 1;
        
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    bool isPalindrome (string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int minCut(string s) {
        
        int n = s.size();
        vector <int> dp (n + 1, 0);
        dp[n] = 0;       //Base Case (Can be omitted)
            
        
        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
        
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min (mini, cost);
                }
            }

             dp[i] = mini;
        }
        
        return dp[0] - 1;
        
    }
};