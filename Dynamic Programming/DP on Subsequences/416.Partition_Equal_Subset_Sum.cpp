//Problem Link :- https://leetcode.com/problems/partition-equal-subset-sum/

//Solved by Memoization Method
class Solution {
public:
    
    bool func (int index, int target, vector <vector <int>> &dp, vector<int>& nums)
    {
        if (target == 0)
            return true;
        
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
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0; 
        
        for (auto it : nums)
            sum += it;
        
        if (sum & 1)
            return false;
        
        int k = sum / 2;
        
        int n = nums.size();
        vector <vector <int>> dp(n, vector <int> (k + 1, -1));
        
        return func (n - 1, k, dp, nums);
    }
};

//Solved by Tabulation Method

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0; 
        
        for (auto it : nums)
            sum += it;
        
        if (sum & 1)
            return false;
        
        int k = sum / 2;
        
        int n = nums.size();
        
        vector <vector <bool>> dp(n + 1, vector <bool> (k + 1, false));

        for (int index = 0; index <= n; index++)
            dp[index][0] = true;
    
        for (int index = 1; index <= n; index++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool left = dp[index - 1][target];
                bool taken = false;
                
                if (nums[index - 1] <= target)
                    taken = dp[index - 1][target - nums[index - 1]];
                
                dp[index][target] = taken | left;
            }
        }
        
        return dp[n][k];
    }
};


//Solved by Tabulation Method (Space Optimized)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0; 
        
        for (auto it : nums)
            sum += it;
        
        if (sum & 1)
            return false;
        
        int k = sum / 2;
        
        int n = nums.size();
        
        vector <bool> dp (k+1, false);
    
    dp[0] = true;
    
    for (int index = 1; index <= n; index++)
    {
        vector <bool> temp (k+1, false);
        temp[0] = true;
        
        for (int target = 1; target <=k; target++)
        {
            bool left = dp[target];
            bool taken = false;
            
            if (nums[index - 1] <= target)
                taken = dp[target - nums[index - 1]];
            
            temp[target] = taken | left;
        }
        
        dp = temp;
    }
    
        return dp[k];
    }
};