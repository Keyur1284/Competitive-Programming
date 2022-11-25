//Problem Link :- https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344

//Solved by Memoization Method

#include <bits/stdc++.h> 

int func (int i, int j, vector <vector <int>> &dp, vector<int> &arr)
{
    if (i == j)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + func (i, k, dp, arr) + func (k + 1, j, dp, arr);
        
        mini = min (mini, steps);
    }
        
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    int n = N;
    vector <vector <int>> dp (n, vector <int> (n,-1));
    return func (1, n - 1, dp, arr);
}


//Solved by Tabulation Method

#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    int n = N;
    vector <vector <int>> dp (n, vector <int> (n, -1));
    
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = INT_MAX;
            
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        
                mini = min (mini, steps);
            }
            
            dp[i][j] = mini;
        }
    }
    
    return dp[1][n - 1];
}