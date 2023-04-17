//Problem Link :- https://leetcode.com/problems/triangle/

//Solved by Memoization Method
class Solution {
public:
    int func (int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if (i == n - 1)
            return triangle[n-1][j];
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int down = triangle[i][j] + func(i+1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + func(i+1, j+1, n, triangle, dp);
        
        return dp[i][j] = min (down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        return func(0, 0, n, triangle, dp);
    }
};


//Solved by Tabulation Method
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        
        for (int j = 0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for (int i = n - 2; i>=0; i--)
        {
            for (int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
        
                dp[i][j] = min (down, diagonal);
            }
        }
        
        return dp[0][0];
    }
};

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        
        for (int i = n - 1; i>=0; i--)
        {
            for (int j = i; j>=0; j--)
            {
                if (i == n - 1)
                {
                    dp[i][j] = triangle[i][j];
                    continue;
                }

                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
        
                dp[i][j] = min (down, diagonal);
            }
        }
        
        return dp[0][0];
    }
};

//Solved by Tabulation Method (Space Optimized)
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> dp (n);
        
        for (int j = 0; j < n; j++)
            dp[j] = triangle[n-1][j];
        
        for (int i = n - 2; i>=0; i--)
        {
            vector <int> temp(n);
            
            for (int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + dp[j];
                int diagonal = triangle[i][j] + dp[j+1];
        
                temp[j] = min (down, diagonal);
            }
            
            dp = temp;
        }
        
        return dp[0];
    }
};

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> dp (n);

        for (int i = n - 1; i>=0; i--)
        {
            vector <int> temp(n);
            
            for (int j = i; j>=0; j--)
            {
                if (i == n - 1)
                {
                    temp[j] = triangle[i][j];
                    continue;
                }
                
                int down = triangle[i][j] + dp[j];
                int diagonal = triangle[i][j] + dp[j+1];
        
                temp[j] = min (down, diagonal);
            }
            
            dp = temp;
        }
        
        return dp[0];
    }
};