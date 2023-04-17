//Problem Link :- https://leetcode.com/problems/unique-paths/

//Solved by Memoization Method
class Solution {
public:
    int func (int x, int y, vector <vector <int>> &dp)
    {      
        if (x == 0 && y == 0)
            return 1;
        
        if (x < 0 || y < 0)
            return 0;
        
        if (dp[x][y] != -1)
            return dp[x][y];
        
        int up = func (x - 1, y, dp);
        int left = func (x, y - 1, dp);
        
        return dp[x][y] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        
        vector <vector<int>> dp (m, vector <int> (n, -1));
        return func (m - 1, n - 1, dp);
    }
};


//Solved by Tabulation Method
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector <vector<int>> dp (m, vector <int> (n, 0));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                
                if (i > 0)
                    up = dp[i-1][j];
                
                if (j > 0)
                    left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }
        
        return dp[m-1][n-1];
    }
};


//Solved by Tabulation Method (Space Optimized)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> dp (n, 0);
        
        for (int i = 0; i < m; i++)
        {
            vector<int> temp (n, 0);
            
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }
                
                int up = 0, left = 0;
                
                if (i > 0)
                    up = dp[j];
                
                if (j > 0)
                    left = temp[j-1];
                
                temp[j] = up + left;
            }
            
            dp = temp;
        }
        
        return dp[n-1];
    }
};
    

//Solved by Combinatorics

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        long long ans = 1;

        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
        {
            ans = (ans * i)/j;
        }

        return ans;
    }
};