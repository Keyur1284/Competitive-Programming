// Problem Link :- https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size(), maxOrValue = 0;
        
        for (int num : nums)
            maxOrValue |= num;
        
        return countSubsets(0, 0, maxOrValue, n, nums);
    }

private:
    int countSubsets(int index, int currentOr, int targetOr, int n, vector<int>& nums) 
    {
        if (index == n)
            return (currentOr == targetOr);

        int countWithout = countSubsets(index + 1, currentOr, targetOr, n, nums); 
        int countWith = countSubsets(index + 1, currentOr | nums[index], targetOr, n, nums);

        return countWithout + countWith;
    }
};



// Solved by Memoization Method
// Time Complexity :- O(n * maxOrValue)
// Space Complexity :- O(n * maxOrValue)

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size(), maxOrValue = 0;

        for (int num : nums)
            maxOrValue |= num;

        vector<vector<int>> dp(n, vector<int>(maxOrValue + 1, -1));
        return countSubsetsRecursive(0, 0, maxOrValue, n, nums, dp);
    }

private:
    int countSubsetsRecursive(int index, int currentOr, int targetOr, int n, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (index == n)
            return (currentOr == targetOr);

        if (dp[index][currentOr] != -1)
            return dp[index][currentOr];

        int countWithout = countSubsetsRecursive(index + 1, currentOr, targetOr, n, nums, dp);
        int countWith = countSubsetsRecursive(index + 1, currentOr | nums[index], targetOr, n, nums, dp);

        return dp[index][currentOr] = countWithout + countWith;
    }
};