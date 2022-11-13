//Problem Link :- https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Solved by Memoization Method
#include <bits/stdc++.h> 
int recc (int index, vector <int> &heights, vector <int>  &dp)
{
    if (index == 0)
        return 0;
    
    if (dp[index] != -1)
        return dp[index];
    
    int left = recc (index - 1, heights, dp) + abs (heights[index] - heights[index-1]);
    int right = INT_MAX;
    
    if (index > 1)
        right = recc (index - 2, heights, dp) + abs (heights[index] - heights[index-2]);
    
    return dp[index] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector <int> dp (n, -1);
    return recc (n - 1, heights, dp);
}


//Solved by Tabulation Method
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector <int> dp (n, -1);
    dp[0] = 0;
    
    for (int i = 1; i <= n-1; i++)
    {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        
        if (i > 1)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(left, right);
    }
    
    return dp[n-1];
}


//Most optimized code (Using least space)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0, curr;
    
    for (int i = 1; i<=n-1; i++)
    {
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i-2]);
        
        curr = min (left, right);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}