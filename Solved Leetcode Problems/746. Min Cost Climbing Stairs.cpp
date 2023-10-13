// Problem Link :- https://leetcode.com/problems/min-cost-climbing-stairs/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int solve (int index, int &n, vector<int> &dp, vector<int> &cost)
    {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int currcost = cost[index] + min(solve(index + 1, n, dp, cost), solve (index + 2, n, dp, cost));

        return dp[index] = currcost;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp (n, -1);
        
        return min(solve (0, n, dp, cost), solve (1, n, dp, cost));
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp (n + 2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
        }

        return min(dp[0], dp[1]);
    }
};