// Problem Link :- https://leetcode.com/problems/predict-the-winner/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    
    int solve (int start, int end, int turn, vector<vector<vector<int>>> &dp, vector<int> &nums)
    {
        if (start > end)
            return 0;

        if (dp[start][end][turn] != -1)
            return dp[start][end][turn];

        int takeLeft, takeRight;

        if (turn == 0)
        {
            takeLeft = nums[start] + solve(start + 1, end, !turn, dp, nums);
            takeRight = nums[end] + solve(start, end - 1, !turn, dp, nums);

            return dp[start][end][turn] = max(takeLeft, takeRight);
        }

        else
        {
            takeLeft = -nums[start] + solve(start + 1, end, !turn, dp, nums);
            takeRight = -nums[end] + solve(start, end - 1, !turn, dp, nums);

            return dp[start][end][turn] = min(takeLeft, takeRight);
        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));

        return (solve(0, n - 1, 0, dp, nums) >= 0);
    }
};



class Solution {
public:
    
    int solve (int start, int end, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int takeLeft = nums[start] - solve(start + 1, end, dp, nums);
        int takeRight = nums[end] - solve(start, end - 1, dp, nums);

        return dp[start][end] = max(takeLeft, takeRight);
    }

    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return (solve(0, n - 1, dp, nums) >= 0);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int diff = 1; diff < n; diff++)
        {
            for (int left = 0; left < n - diff; left++)
            {
                int right = left + diff;
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1]);
            }
        }

        return (dp[0][n - 1] >= 0);
    }
};