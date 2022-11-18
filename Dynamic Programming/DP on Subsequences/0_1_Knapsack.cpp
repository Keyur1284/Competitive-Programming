//Problem Link :- https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

//Solved by Memoization Method
#include <bits/stdc++.h> 

int func (int index, int maxWt, vector<int> &weight, vector<int> &value, vector <vector <int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= maxWt)
            return value[index];
        
        else
            return 0;
    }
    
    if (dp[index][maxWt] != 0)
        return dp[index][maxWt];
    
    int notTake = 0 + func (index - 1, maxWt, weight, value, dp);
    int take = INT_MIN;
    
    if (weight[index] <= maxWt)
        take = value[index] + func (index - 1, maxWt - weight[index], weight, value, dp);
        
        return dp[index][maxWt] = max (take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector <vector <int>> dp (n, vector <int> (maxWeight + 1, 0));
    
    return func (n - 1, maxWeight, weight, value, dp);
}


//Solved by Tabulation Method
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWt) 
{
    vector <vector <int>> dp (n, vector <int> (maxWt + 1, 0));
    
    for (int i = weight[0]; i <= maxWt; i++)
        dp[0][i] = value[0];
    
    for (int index = 1; index < n; index++)
    {
        for (int cap = 0; cap <= maxWt; cap++)
        {
            int notTake = 0 + dp[index - 1][cap];
            int take = INT_MIN;
            
            if (weight[index] <= cap)
                take = value[index] + dp[index - 1][cap - weight[index]];
                
            dp[index][cap] = max (take, notTake);
        }
    }
    
    return dp[n - 1][maxWt];
}


//Solved by Tabulation Method (Little Space Optimized) (using 2 rows)
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWt) 
{
    vector <int>dp (maxWt + 1, 0);
    
    for (int i = weight[0]; i <= maxWt; i++)
        dp[i] = value[0];
    
    for (int index = 1; index < n; index++)
    {
        vector <int> temp (maxWt + 1, 0);
        
        for (int cap = 0; cap <= maxWt; cap++)
        {
            int notTake = 0 + dp[cap];
            int take = INT_MIN;
            
            if (weight[index] <= cap)
                take = value[index] + dp[cap - weight[index]];
                
            temp[cap] = max (take, notTake);
        }
        
        dp = temp;
    }
    
    return dp[maxWt];
}


//Solved by Tabulation Method (Best Space Optimized) (using only 1 row)
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWt) 
{
    vector <int>dp (maxWt + 1, 0);
    
    for (int i = weight[0]; i <= maxWt; i++)
        dp[i] = value[0];
    
    for (int index = 1; index < n; index++)
    {        
        for (int cap = maxWt; cap >= 0; cap--)
        {
            int notTake = 0 + dp[cap];
            int take = INT_MIN;
            
            if (weight[index] <= cap)
                take = value[index] + dp[cap - weight[index]];
                
            dp[cap] = max (take, notTake);
        } 
    }
    
    return dp[maxWt];
}