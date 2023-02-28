//Problem Link :- https://leetcode.com/problems/target-sum/

// This problem is same as the partition with given difference problem of coding studio

//Solved by Memoization Method
class Solution {
public:
    int func (int index, int target, vector<int>& nums, vector <vector<int>> & dp)
    {
        if (index == 0)
        {
            if (target == 0 && nums[index] == 0)
                return 2;
            
            if (target == 0 || nums[index] == target)
                return 1;
            
            else
                return 0;
        }
        
        if (dp[index][target] != -1)
            return dp[index][target];
        
        int notTake = 0 + func (index - 1, target, nums, dp);
        int take = 0;
        
        if (nums[index] <= target)
            take += func (index - 1, target - nums[index], nums, dp);
        
        return dp[index][target] = take + notTake;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for (auto it : nums)
            sum += it;
        
        if (sum - target < 0 || (sum - target) & 1)
            return 0;
        
        int k = (sum - target)/2;
        
        vector <vector<int>> dp(n, vector <int> (k + 1, -1));
        
        return func (n - 1, k, nums, dp);
    }
};


//Solved by Tabulation Method
class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for (auto it : nums)
            sum += it;
        
        if (sum - target < 0 || (sum - target) & 1)
            return 0;
        
        int k = (sum - target)/2;
        
        vector <vector <int>> dp (n + 1, vector <int> (k + 1 , 0));
    
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int index = 1; index <= n; index++)
        {
            for (int j = 0; j <= k; j++)
            {
                int left = dp[index - 1][j];
                int taken = 0;

                if (nums[index - 1] <= j)
                    taken = dp[index - 1][j - nums[index - 1]];

                dp[index][j] = taken + left;
            }
        }
    
        return dp[n][k];
    }
};


//Solved by Tabulation Method
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for (auto it : nums)
            sum += it;
        
        if (sum - target < 0 || (sum - target) & 1)
            return 0;
        
        int k = (sum - target)/2;
        
        vector <vector<int>> dp(n, vector <int> (k + 1, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (i == 0)
                {
                    if (j == 0 && nums[i] == 0)
                        dp[i][j] = 2;
                    
                    else if (j == 0 || nums[i] == j)
                        dp[i][j] = 1;
                    
                    else
                        dp[i][j] = 0;
                }
                
                else
                {
                    int notTake = 0 + dp[i - 1][j];
                    int take = 0;
                    
                    if (nums[i] <= j)
                        take += dp[i - 1][j - nums[i]];
                    
                    dp[i][j] = take + notTake;
                }
            }
        }
        
        return dp[n - 1][k];
    } 
};


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for (auto it : nums)
            sum += it;
        
        if (sum - target < 0 || (sum - target) & 1)
            return 0;
        
        int k = (sum - target)/2;
        
        vector <int> dp (k + 1, 0);
        dp[0] = 1;
    
        for (int index = 1; index <= n; index++)
        {
            vector <int> temp (k + 1, 0);
            temp[0] = 1;

            for (int j = 0; j <= k; j++)
            {
                int left = dp[j];
                int taken = 0;

                if (nums[index - 1] <= j)
                    taken = dp[j - nums[index - 1]];

                temp[j] = taken + left;
            }

            dp = temp;
        }
    
        return dp[k];
    }
};


//Solved by Tabulation Method (Best Space Optimized) (Using 1 row only)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for (auto it : nums)
            sum += it;
        
        if (sum - target < 0 || (sum - target) & 1)
            return 0;
        
        int k = (sum - target)/2;
        
        vector <int> dp(k + 1, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = k; j >= 0; j--)
            {
                if (i == 0)
                {
                    if (j == 0 && nums[i] == 0)
                        dp[j] = 2;
                    
                    else if (j == 0 || nums[i] == j)
                        dp[j] = 1;
                    
                    else
                        dp[j] = 0;
                }
                
                else
                {
                    int notTake = 0 + dp[j];
                    int take = 0;
                    
                    if (nums[i] <= j)
                        take += dp[j - nums[i]];
                    
                    dp[j] = take + notTake;         //  dp[index][j] =  dp[index - 1][j] + dp[index - 1][j - nums[index]]
                }
            }
        }
        
        return dp[k];
    } 
};