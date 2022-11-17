//Problem Link: https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

//Solved by Memoization Method
#include <bits/stdc++.h> 
bool func (int index, int target, vector <vector <int>> &dp, vector<int>& nums)
{
    if (target == 0)
        return dp[index][target] = true;

    if (index == 0)
        return (nums[index] == target);

    if (dp[index][target] != -1)
        return dp[index][target];

    bool left = func (index - 1, target, dp, nums);
    bool taken = false;

    if (nums[index] <= target)
        taken = func (index - 1, target - nums[index], dp, nums);

    return dp[index][target] = taken | left;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    
    for (auto it : arr)
        sum += it;
    
    int target = sum;
    
    vector <vector <int>> dp(n, vector <int> (target + 1, -1));
    
    for (int k = 0; k <= target; k++)
        func (n - 1, k, dp, arr);
    
    int mini = 1e9;
    
    for (int i = 0; i <= target; i++) 
    {
        if (dp[n - 1][i] == true) 
        {
            int diff = abs(i - (target - i));
            mini = min(mini, diff);
        }
    }
    return mini;
    
}



//Solved by Tabulation Method
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;

    for (auto it : arr)
        sum += it;

    int target = sum;

    vector <vector <bool>> dp(n + 1, vector <bool> (target + 1, false));

    for (int index = 0; index <= n; index++)
        dp[index][0] = true;

    for (int index = 1; index <= n; index++)
    {
        for (int k = 0; k <= target; k++)
        {
            bool left = dp[index - 1][k];
            bool taken = false;

            if (arr[index - 1] <= k)
                taken = dp[index - 1][k - arr[index - 1]];

            dp[index][k] = taken | left;
        }
    }

    int mini = 1e9;

    for (int i = 0; i <= target; i++) 
    {
        if (dp[n - 1][i] == true) 
        {
            int diff = abs(i - (target - i));
            mini = min(mini, diff);
        }
    }
    return mini;

}



//Solved by Tabulation Method (Space Optimized)
#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;

    for (auto it : arr)
        sum += it;

    int target = sum;

    vector <bool> dp (target+1, false);

    dp[0] = true;

    for (int index = 1; index <= n; index++)
    {
        vector <bool> temp (target+1, false);
        temp[0] = true;

        for (int k = 0; k <= target; k++)
        {
            bool left = dp[k];
            bool taken = false;

            if (arr[index - 1] <= k)
                taken = dp[k - arr[index - 1]];

            temp[k] = taken | left;
        }

        dp = temp;
    }
    int mini = 1e9;

    for (int i = 0; i <= target; i++) 
    {
        if (dp[i] == true) 
        {
            int diff = abs(i - (target - i));
            mini = min(mini, diff);
        }
    }
    return mini;

}
