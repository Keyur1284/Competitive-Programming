// Problem Link :- https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    bool solve (int index, vector<int> &dp, vector<int> &nums)
    {
        if (index < 0)
            return true;
        
        if (dp[index] != -1)
            return dp[index];

        bool ans = false;

        if (index >= 1 && nums[index] == nums[index - 1])
        {
            ans |= solve (index - 2, dp, nums);

            if (index >= 2 && nums[index] == nums[index - 2])
                ans |= solve (index - 3, dp, nums);
        }

        if (index >= 2 && nums[index] - nums[index - 1] == 1 && nums[index - 1] - nums[index - 2] == 1)
            ans |= solve (index - 3, dp, nums);

        return dp[index] = ans;
    }

    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve (n - 1, dp, nums);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int index = 1; index <= n; index++)
        {
            bool ans = false;

            if (index >= 2 && nums[index - 1] == nums[index - 2])
            {
                ans |= dp[index - 2];

                if (index >= 3 && nums[index - 1] == nums[index - 3])
                    ans |= dp[index - 3];
            }

            if (index >= 3 && nums[index - 1] - nums[index - 2] == 1 && nums[index - 2] - nums[index - 3] == 1)
                ans |= dp[index - 3];

            dp[index] = ans;
        }

        return dp[n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> dp(3, false);
        dp[0] = true;

        for (int index = 1; index <= n; index++)
        {
            bool ans = false;

            if (index >= 2 && nums[index - 1] == nums[index - 2])
            {
                ans |= dp[(index - 2) % 3];

                if (index >= 3 && nums[index - 1] == nums[index - 3])
                    ans |= dp[(index - 3) % 3];
            }

            if (index >= 3 && nums[index - 1] - nums[index - 2] == 1 && nums[index - 2] - nums[index - 3] == 1)
                ans |= dp[(index - 3) % 3];

            dp[(index) % 3] = ans;
        }

        return dp[n % 3];
    }
};