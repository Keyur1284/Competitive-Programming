// Problem Link :- https://leetcode.com/problems/maximum-subarray/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by Memoization Method

class Solution {
public:

    int func (int index, bool flag, vector<vector<int>> &dp, vector<int>& nums)
    {
        if (index == -1)
            return flag ? 0 : -1e6;

        if (dp[index][flag] != -1)
            return dp[index][flag];

        if (flag)
            return dp[index][flag] = max(0, nums[index] + func(index - 1, true, dp, nums));

        int notPick = 0 + func(index - 1, false, dp, nums);
        int pick = nums[index] + func (index - 1, true, dp, nums);

        return dp[index][flag] = max(pick, notPick);
    } 

    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int> (2, -1));

        return func(n - 1, false, dp, nums);
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by Tabulation Method

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int> (2, 0));

        dp[0][0] = nums[0], dp[0][1] = nums[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][1] = max(nums[i], nums[i] + dp[i - 1][1]);
            dp[i][0] = max(dp[i - 1][0], dp[i][1]);
        }

        return dp[n - 1][0];
    }
};


class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), maxi = nums[0];
        vector<int> dp(n);        
        
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxi = max(dp[i], maxi);
        }

        return maxi;
    }
};

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by Prefix Sum Method

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pref = nums;

        for (int i = 1; i < n; i++)
            pref[i] += max(0, pref[i - 1]);

        return *max_element(pref.begin(), pref.end());
    }
};

// Time Complexity :- O(n)
// Space Complexity :- O(1)

// Solved by Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, ans = INT_MIN;

        for (auto &it : nums)
        {
            sum += it;

            ans = max(ans, sum);
            sum = max(0, sum);
        }

        return ans;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

// Printing the maximum subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0, ans = INT_MIN, temp, start, end;

        for (int i = 0; i < n; i++)
        {
            if (sum == 0)
                temp = i;

            sum += nums[i];

            if (sum > ans)
            {
                ans = sum;
                start = temp;
                end = i;
            }

            sum = max(0, sum);
        }

        for (int i = start; i <= end; i++)
            cout << nums[i] << " ";

        return ans;
    }
};