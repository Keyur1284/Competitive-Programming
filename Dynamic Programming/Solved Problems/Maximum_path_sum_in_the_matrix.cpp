//Problem Link :- https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//Solved by Memoization Method
#include <bits/stdc++.h> 

int func (int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return -1e9;
    
    if (i == 0)
        return matrix[i][j];
    
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int up = func(i - 1, j, m, matrix, dp);
    int leftDiagonal = func(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = func(i - 1, j + 1, m, matrix, dp);
    
    return dp[i][j] = matrix[i][j] + max (up, max (leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    
    vector<vector<int>> dp(n, vector <int> (m, -1));
    
    for (int j = 0; j < m; j++)
    {
        int ans = func (n-1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }
    
    return maxi;
}


//Solved by Tabulation Method
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    
    vector<vector<int>> dp(n, vector <int> (m, -1));
    
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int leftDiagonal = -1e9, rightDiagonal = -1e9;
            
            int up = dp[i - 1][j];
            
            if (j > 0)
                leftDiagonal = dp[i - 1][j - 1];
            
            if (j < m - 1)
                rightDiagonal = dp[i - 1][j + 1];
            
            dp[i][j] = matrix[i][j] + max (up, max (leftDiagonal, rightDiagonal));
        }
    }
    
    for (int j = 0; j < m; j++)
        maxi = max (maxi, dp[n - 1][j]);
    
    return maxi;
}


//Solved by Tabulation Method (Space Optimized)
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    
    vector<int> dp(m, -1);
    
    for (int j = 0; j < m; j++)
        dp[j] = matrix[0][j];
    
    for (int i = 1; i < n; i++)
    {
        vector <int> temp (m, -1);
        
        for (int j = 0; j < m; j++)
        {
            int leftDiagonal = -1e9, rightDiagonal = -1e9;
            
            int up = dp[j];
            
            if (j > 0)
                leftDiagonal = dp[j - 1];
            
            if (j < m - 1)
                rightDiagonal = dp[j + 1];
            
            temp[j] = matrix[i][j] + max (up, max (leftDiagonal, rightDiagonal));
        }
        
        dp = temp;
    }
    
    for (int j = 0; j < m; j++)
        maxi = max (maxi, dp[j]);
    
    return maxi;
}