// Problem Link :- https://leetcode.com/problems/house-robber/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int DP(int index, vector <int> &nums, vector <int> &dp)
    {
        if(index == 0)  
            return nums[index];
        
        if (index < 0)
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        int pick = nums[index] + DP(index - 2, nums, dp);
        int nonPick = 0 + DP(index - 1, nums, dp);
        
        return dp[index] = max(pick, nonPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, -1);
        
        return DP(n - 1, nums, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> dp(n, -1);
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            
            if (i > 1)
                pick += dp[i - 2];
            
            int nonPick = 0 + dp[i - 1];
            
            dp[i] = max(pick, nonPick);
        }
        
        return dp[n - 1];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        int prev = nums[0], prev2 = 0, curr;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i] + prev2;
            int nonPick = prev;
            
            curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};