//Problem Link :- https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

//Solved by Memoization Method
#include <bits/stdc++.h> 

int func (int index, int target, vector <vector <int>> &dp, vector<int> &num)
{
    if (index == 0)
    {
        /*
            Base case if numbers are > 0
            
            if (target == 0)
                return 1;
        
            if (index == 0)
                return (num[index] == target);
        */

        if (target == 0 && num[index] == 0)
            return 2;
        
        if (target == 0 || num[index] == target)
            return 1;
        
        else
            return 0;
    }
    
    if (dp[index][target] != -1)
        return dp[index][target];
    
    int notPick = func (index - 1, target, dp, num);
    int pick = 0;
    
    if (num[index] <= target)
        pick = func (index - 1, target - num[index], dp, num);
    
    return dp[index][target] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector <vector <int>> dp (n, vector <int> (tar + 1, -1));
    
    return func (n - 1, tar, dp, num);
}


//Solved by Tabulation Method
#include <bits/stdc++.h> 

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector <vector <int>> dp (n + 1, vector <int> (tar + 1, 0));
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
    for (int index = 1; index <= n; index++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int left = dp[index - 1][target];
            int taken = 0;
            
            if (num[index - 1] <= target)
                taken = dp[index - 1][target - num[index - 1]];
            
            dp[index][target] = taken + left;
        }
    }
    
    return dp[n][tar];
}


//Solved by Tabulation Method (Space Optimized)
#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector <int> dp (tar + 1, 0);
  
    dp[0] = 1;
    
    for (int index = 1; index <= n; index++)
    {
        vector <int> temp (tar + 1, 0);
        temp[0] = 1;
        
        for (int target = 0; target <= tar; target++)
        {
            int left = dp[target];
            int taken = 0;
            
            if (num[index - 1] <= target)
                taken = dp[target - num[index - 1]];
            
            temp[target] = taken + left;
        }
        
        dp = temp;
    }
    
    return dp[tar];
}