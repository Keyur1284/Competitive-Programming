//Problem Link :- https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

//Solved by Memoization Method
#include <bits/stdc++.h> 

bool func (int index, int target, vector <vector <int>> &dp, vector<int> &arr)
{
    if (target == 0)
        return true;
    
    if (index == 0)
        return (arr[0] == target);
    
    if (dp[index][target] != -1)
        return dp[index][target];
    
    bool left = func (index - 1, target, dp, arr);
    bool taken = false;
    
    if (arr[index] <= target)
        taken = func (index - 1, target - arr[index], dp, arr);
    
    return dp[index][target] = taken | left;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector <vector <int>> dp (n, vector <int> (k+1, -1));
    
    return func (n - 1, k, dp, arr);
}



//Solved by Tabulation Method
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector <vector <bool>> dp (n, vector <bool> (k+1, false));
    
    for (int index = 0; index < n; index++)
        dp[index][0] = true;
    
    for (int index = 0; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            if (index == 0)
            {
                dp[index][target] = (arr[index] == target);
                continue;
            }
            
            bool left = dp[index - 1][target];
            bool taken = false;
            
            if (arr[index] <= target)
                taken = dp[index - 1][target - arr[index]];
            
            dp[index][target] = taken | left;
        }
    }
    
    return dp[n-1][k];
}



//Solved by Tabulation Method (Space Optimized)
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector <bool> dp (k+1, false);
    
    dp[0] = true;
    
    if (arr[0] <= k)
        dp[arr[0]] = true;
    
    for (int index = 1; index < n; index++)
    {
        vector <bool> temp (k+1, false);
        temp[0] = true;
        
        for (int target = 1; target <=k; target++)
        {
            bool left = dp[target];
            bool taken = false;
            
            if (arr[index] <= target)
                taken = dp[target - arr[index]];
            
            temp[target] = taken | left;
        }
        
        dp = temp;
    }
    
    return dp[k];
}

