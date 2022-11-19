//Problem Link :- https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628


//Solved by Memoization Method
#include <bits/stdc++.h> 

int MOD = (int)1e9 + 7;

int func (int index, int target, vector <vector <int>> &dp, vector<int> &num)
{
    if (index == 0)
    {
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
    
    return dp[index][target] = (pick + notPick) % MOD;
}

int countPartitions(int n, int d, vector<int> &arr) {
    
    int sum = 0;
    
    for (auto it : arr)
        sum += it;
    
    if (sum - d < 0 || (sum - d) & 1)
        return 0;
    
    int target = (sum - d) / 2;
        
    vector <vector <int>> dp (n, vector <int> (target +1 , -1));
    
    return func (n - 1, target, dp, arr);
}



//Solved by Tabulation Method
#include <bits/stdc++.h> 

int MOD = (int)1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    
    int sum = 0;
    
    for (auto it : arr)
        sum += it;
    
    if (sum - d < 0 || (sum - d) & 1)
        return 0;
    
    int target = (sum - d) / 2;
        
    vector <vector <int>> dp (n + 1, vector <int> (target + 1 , 0));
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
    for (int index = 1; index <= n; index++)
    {
        for (int k = 0; k <= target; k++)
        {
            int left = dp[index - 1][k];
            int taken = 0;
            
            if (arr[index - 1] <= k)
                taken = dp[index - 1][k - arr[index - 1]];
            
            dp[index][k] = (taken + left) % MOD;
        }
    }
    
    return dp[n][target];
}


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)
#include <bits/stdc++.h> 

int MOD = (int)1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    
    int sum = 0;
    
    for (auto it : arr)
        sum += it;
    
    if (sum - d < 0 || (sum - d) & 1)
        return 0;
    
    int target = (sum - d) / 2;
    
    vector <int> dp (target + 1, 0);
    dp[0] = 1;
    
    for (int index = 1; index <= n; index++)
    {
        vector <int> temp (target + 1, 0);
        temp[0] = 1;
        
        for (int k = 0; k <= target; k++)
        {
            int left = dp[k];
            int taken = 0;
            
            if (arr[index - 1] <= k)
                taken = dp[k - arr[index - 1]];
            
            temp[k] = (taken + left) % MOD;
        }
        
        dp = temp;
    }
    
    return dp[target];
}


//Solution by Tabulation Method (Best Space Optimized) (Using 1 row)
#include <bits/stdc++.h> 

int MOD = (int)1e9 + 7;

int countPartitions(int n, int d, vector<int> &arr) {
    
    int sum = 0;
    
    for (auto it : arr)
        sum += it;
    
    if (sum - d < 0 || (sum - d) & 1)
        return 0;
    
    int target = (sum - d) / 2;
    
    vector <int> dp (target + 1, 0);            
    
    for (int index = 0; index < n; index++)
    {
        for (int k = target; k >= 0; k--)
        {
            if (index == 0)
            {
                if (k == 0 && arr[index] == 0)
                    dp[k] = 2;
                
                else if (k == 0 || arr[index] == k)
                    dp[k] = 1;
                
                else
                    dp[k] = 0;
             }
            
            else
            {
                int left = dp[k];
                int taken = 0;

                if (arr[index] <= k)
                    taken = dp[k - arr[index]];

                dp[k] = (taken + left) % MOD;       //  dp[index][k] =  dp[index - 1][k] + dp[index - 1][k - arr[index]]
            }
        }
    }
    
    return dp[target];
}