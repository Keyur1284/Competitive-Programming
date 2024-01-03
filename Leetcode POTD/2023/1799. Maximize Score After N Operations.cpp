// Problem Link :- https://leetcode.com/problems/maximize-score-after-n-operations/

// Time Complexity :- O(2^m * (m) ^2 * log A)  -->  m = 2 * n
// Space Complexity :- O(n + 2^m)

// Solved by Memoization Method

class Solution {
public:

    int solve (int pairs, int mask, int n, vector<int> &nums, vector<int> &dp)
    {
        if (2 * pairs == n)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        int score = 0;

        for (int first = 0; first < n; first++)
        {
            if ((mask >> first) & 1)
                continue;

            for (int second = first + 1; second < n; second++)
            {
                if ((mask >> second) & 1)
                    continue;

                int newMask = mask | 1 << first | 1 << second;

                int curr = (pairs + 1) * (__gcd(nums[first], nums[second]));
                int rem = solve (pairs + 1, newMask, n, nums, dp);

                score = max(score, curr + rem);
            }
        }

        return dp[mask] = score;
    }

    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int size = 1 << n;

        vector<int> dp (size, -1);

        return solve (0, 0, n, nums, dp);
    }
};


// Solved by Tabulation Method

class Solution {
public:

    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int size = 1 << n;
        int final = size - 1;
        vector<int> dp (size, 0);

        for (int mask = final; mask >= 0; mask--)
        {
            if (mask == final)
            {
                dp[mask] = 0;
                continue;
            }

            int countNums = __builtin_popcount(mask);

            if (countNums & 1)
                continue;

            int pairs = countNums/2;
            int score = 0;

            for (int first = 0; first < n; first++)
            {
                if ((mask >> first) & 1)
                    continue;

                for (int second = first + 1; second < n; second++)
                {
                    if ((mask >> second) & 1)
                        continue;

                    int newMask = mask | 1 << first | 1 << second;

                    int curr = (pairs + 1) * (__gcd(nums[first], nums[second]));
                    int rem = dp[newMask];

                    score = max(score, curr + rem);
                }
            }

            dp[mask] = score;
        }

        return dp[0];
    }
};