// Problem Link :- https://leetcode.com/problems/tallest-billboard/

// Solved by Memoization Method
// Time Complexity :- O(n * sum)
// Space Complexity :- O(n * sum)

class Solution {
public:

    int solve (int index, int diff, int &offset, vector<vector<int>> &dp, vector<int>& rods)
    {
        if (index < 0)
        {
            return (diff == 0) ? 0 : INT_MIN;
        }

        if (dp[index][diff + offset] != -1)
            return dp[index][diff + offset];

        int notTake = solve (index - 1, diff, offset, dp, rods);
        int take1 = rods[index] + solve (index - 1, diff + rods[index], offset, dp, rods);
        int take2 = solve (index - 1, diff - rods[index], offset, dp, rods);

        return dp[index][diff + offset] = max({notTake, take1, take2});
    }

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        int offset = accumulate(rods.begin(), rods.end(), 0);

        vector<vector<int>> dp (n, vector<int> (2 * offset + 1, -1));

        int tallestBill = solve (n - 1, 0, offset, dp, rods);

        return (tallestBill < 0) ? 0 : tallestBill;
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(n * sum)
// Space Complexity :- O(n * sum)

class Solution {
public:

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        int offset = accumulate(rods.begin(), rods.end(), 0);

        vector<vector<int>> dp (n + 1, vector<int> (2 * offset + 1, 0));

        for (int index = 0; index <= n; index++)
        {
            for (int diff = -offset; diff <= offset; diff++)
            {
                if (index == 0)
                {
                    dp[index][diff + offset] = (diff == 0)? 0 : INT_MIN;
                    continue;
                }

                int take1 = INT_MIN, take2 = INT_MIN;

                int notTake = dp[index - 1][diff + offset];

                if (diff + rods[index - 1] + offset >= 0 && diff + rods[index - 1] + offset < 2 * offset + 1)
                    take1 = rods[index - 1] + dp[index - 1][diff + rods[index - 1] + offset];

                if (diff - rods[index - 1] + offset >= 0 && diff - rods[index - 1] + offset < 2 * offset + 1)
                    take2 = dp[index - 1][diff - rods[index - 1] + offset];

                dp[index][diff + offset] = max({notTake, take1, take2});
            }
        }

        return (dp[n][0 + offset] < 0) ? 0 : dp[n][0 + offset];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * sum)
// Space Complexity :- O(sum)

class Solution {
public:

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        int offset = accumulate(rods.begin(), rods.end(), 0);

        vector<int> dp (2 * offset + 1, 0);

        for (int index = 0; index <= n; index++)
        {
            vector<int> temp (2 * offset + 1, 0);

            for (int diff = -offset; diff <= offset; diff++)
            {
                if (index == 0)
                {
                    temp[diff + offset] = (diff == 0)? 0 : INT_MIN;
                    continue;
                }

                int take1 = INT_MIN, take2 = INT_MIN;

                int notTake = dp[diff + offset];

                if (diff + rods[index - 1] + offset >= 0 && diff + rods[index - 1] + offset < 2 * offset + 1)
                    take1 = rods[index - 1] + dp[diff + rods[index - 1] + offset];

                if (diff - rods[index - 1] + offset >= 0 && diff - rods[index - 1] + offset < 2 * offset + 1)
                    take2 = dp[diff - rods[index - 1] + offset];

                temp[diff + offset] = max({notTake, take1, take2});
            }

            dp = temp;
        }

        return (dp[0 + offset] < 0) ? 0 : dp[0 + offset];
    }
};