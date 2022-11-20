//Problem Link :- https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

//Solved by Memoization Method

#include <bits/stdc++.h> 

int func (int index, int wt, vector <vector <int>> &dp, vector<int> &profit, vector<int> &weight)
{
    if (index == 0)
        return (wt / weight[0]) * profit[0];
    
    if (dp[index][wt] != -1)
        return dp[index][wt];
    
    int notTake = 0 + func (index - 1, wt, dp, profit, weight);
    int take = INT_MIN;
    
    if (weight[index] <= wt)
        take = profit[index] + func (index, wt - weight[index], dp, profit, weight);
    
    return dp[index][wt] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector <vector <int>> dp (n, vector <int> (w + 1, -1));
    
    return func (n - 1, w, dp, profit, weight);
}


//Solved by Tabulation Method

#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector <vector <int>> dp (n, vector <int> (w + 1, 0));
    
    for (int k = 0; k <= w; k++)
        dp[0][k] = (k / weight[0]) * profit[0];
    
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= w; target++)
        {
            int notTake = dp[index - 1][target];
            int take = INT_MIN;
            
            if (weight[index] <= target)
                take = profit[index] + dp[index][target - weight[index]];
            
            dp[index][target] = max (take, notTake);
        }
    }
    
    return dp[n - 1][w];
}


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)

#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector <int> dp (w + 1, 0);
    
    for (int k = 0; k <= w; k++)
        dp[k] = (k / weight[0]) * profit[0];
    
    for (int index = 1; index < n; index++)
    {
        vector <int> temp (w + 1, 0);
        
        for (int target = 0; target <= w; target++)
        {
            int notTake = dp[target];
            int take = INT_MIN;
            
            if (weight[index] <= target)
                take = profit[index] + temp[target - weight[index]];
            
            temp[target] = max (take, notTake);
        }
        
        dp = temp;
    }
    
    return dp[w];
}


//Solved by Tabulation Method (More Space Optimized) (Using 1 row only)

#include <bits/stdc++.h> 
int func (int index, int wt, vector <vector <int>> &dp, vector<int> &profit, vector<int> &weight)
{
    if (index == 0)
        return (wt / weight[0]) * profit[0];
    
    if (dp[index][wt] != -1)
        return dp[index][wt];
    
    int notTake = 0 + func (index - 1, wt, dp, profit, weight);
    int take = INT_MIN;
    
    if (weight[index] <= wt)
        take = profit[index] + func (index, wt - weight[index], dp, profit, weight);
    
    return dp[index][wt] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector <int> dp (w + 1, 0);
    
    for (int k = 0; k <= w; k++)
        dp[k] = (k / weight[0]) * profit[0];
    
    for (int index = 1; index < n; index++)
    {        
        for (int target = 0; target <= w; target++)                 //  dp[ind][cap] =  max(dp[ind-1][cap] ,dp[ind][cap-wt[ind]]
        {
            int notTake = dp[target];
            int take = INT_MIN;
            
            if (weight[index] <= target)
                take = profit[index] + dp[target - weight[index]];
            
            dp[target] = max (take, notTake);
        }
    }
    
    return dp[w];
}
