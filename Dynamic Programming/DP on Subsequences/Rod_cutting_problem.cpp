//Problem Link :- https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

//Solved by Memoization Method

#include <bits/stdc++.h>

int func (int index, int n, vector <vector <int>> &dp, vector<int> &price)
{
    if (index == 0)
        return (n * price[0]);
    
    if (dp[index][n] != -1)
        return dp[index][n];
    
    int notTake = 0 + func (index - 1, n, dp, price);
    int take = INT_MIN;
    int rodLength = index + 1;
    
    if (rodLength <= n)
        take = price[index] + func (index, n - rodLength, dp, price);
    
    dp[index][n] = max (take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector <vector <int>> dp (n, vector <int> (n + 1, -1));
    
    return func (n - 1, n, dp, price);
}



//Solved by Tabulation Method

#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector <vector <int>> dp (n, vector <int> (n + 1, -1));
    
    for (int k = 0; k <= n; k++)
        dp[0][k] = k * price[0];
    
    for (int index = 1; index < n; index++)
    {
        int rodLength = index + 1;

        for (int k = 0; k <= n; k++)
        {
            int notTake = dp[index - 1][k];
            int take = INT_MIN;
            
            if (rodLength <= k)
                take = price[index] + dp[index][k - rodLength];
            
            dp[index][k] = max (take, notTake);
        }
    }
    
    return dp[n - 1][n];
}


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)

#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector <int> dp(n + 1, 0);
    
    for (int k = 0; k <= n; k++)
        dp[k] = k * price[0];
    
    for (int index = 1; index < n; index++)
    {
        int rodLength = index + 1;
        vector <int> temp (n + 1, 0);
        
        for (int k = 0; k <= n; k++)
        {
            int notTake = dp[k];
            int take = INT_MIN;
            
            if (rodLength <= k)
                take = price[index] + temp[k - rodLength];
            
            temp[k] = max (take, notTake);
        }
        
        dp = temp;
    }
    
    return dp[n];
}



//Solved by Tabulation Method (More Space Optimized) (Using 1D Array)

#include <bits/stdc++.h>

int cutRod(vector<int> &price, int n)
{
    vector <int> dp(n + 1, 0);
    
    for (int k = 0; k <= n; k++)
        dp[k] = k * price[0];
    
    for (int index = 1; index < n; index++)
    {
        int rodLength = index + 1;
        
        for (int k = 0; k <= n; k++)                //  dp[ind][length] =  max(dp[ind-1][length] ,dp[ind][length-(ind+1)])
        {
            int notTake = dp[k];
            int take = INT_MIN;
            
            if (rodLength <= k)
                take = price[index] + dp[k - rodLength];
            
            dp[k] = max (take, notTake);
        }
    }
    
    return dp[n];
}
