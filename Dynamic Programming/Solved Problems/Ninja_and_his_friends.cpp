//Problem Link :- https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

//Solved by Memoization Method
#include <bits/stdc++.h> 

int func (int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector < vector < vector < int >>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e9;
    
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        
        else
            return grid[i][j1] + grid[i][j2];
    }
    
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    
    int maxi = INT_MIN;
    
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int ans;
            
            if (j1 == j2)
                ans = grid[i][j1] + func (i + 1, j1 + d1, j2 + d2, r, c, grid, dp);
            
            else
                ans = grid[i][j1] + grid[i][j2] + func (i + 1, j1 + d1, j2 + d2, r, c, grid, dp);
             
            maxi = max(maxi, ans);
        }
    }
    
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector < vector < vector < int >>> dp(r, vector < vector < int >> (c, vector < int > (c, -1)));
    
    return func (0, 0, c - 1, r, c, grid, dp);
}


//Solved by Tabulation Method
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector < vector < vector < int >>> dp(r, vector < vector < int >> (c, vector < int > (c, -1)));
    
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            
            else 
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }
    
    for (int i = r - 2; i>=0; i--)
    {
       for (int j1 = 0; j1 < c; j1++)
       {
           for (int j2 = 0; j2 < c; j2++)
           {
               int maxi = INT_MIN;
    
               for (int d1 = -1; d1 <= 1; d1++)
               {
                   for (int d2 = -1; d2 <= 1; d2++)
                   {
                       int ans = -1e9;
                       
                       if (j1 + d1 >= 0 && j2 + d2 >= 0 && j1 + d1 < c && j2 + d2 < c)
                       {
                           if (j1 == j2)
                               ans = grid[i][j1];

                           else
                               ans = grid[i][j1] + grid[i][j2];
                           
                           ans += dp[i + 1][j1 + d1][j2 + d2];
                       }
                       
                       maxi = max(maxi, ans);
                   }
               }

               dp[i][j1][j2] = maxi;
           }
       }
    }
 
    return dp[0][0][c - 1];
}


//Solved by Tabulation Method (Space Optimized)
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector < vector < int >> dp(c, vector < int > (c, -1));
    
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[j1][j2] = grid[r - 1][j1];
            
            else 
                dp[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }
    
    for (int i = r - 2; i>=0; i--)
    {
        vector < vector < int >> temp(c, vector < int > (c, -1));

        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = INT_MIN;

                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int ans = -1e9;

                        if (j1 + d1 >= 0 && j2 + d2 >= 0 && j1 + d1 < c && j2 + d2 < c)
                        {
                            if (j1 == j2)
                                ans = grid[i][j1];

                            else
                                ans = grid[i][j1] + grid[i][j2];

                            ans += dp[j1 + d1][j2 + d2];
                        }

                        maxi = max(maxi, ans);
                    }
                }

                temp[j1][j2] = maxi;
            }
        }
        
        dp = temp;
    }
 
    return dp[0][c - 1];
}

