// Problem Link :- https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        vector<int> dp(n, -1);

        auto solve = [&](auto solve, int index, char prev, int time)
        {
            if (index < 0)
                return 0;

            if (dp[index] != -1)
                return dp[index];

            int minTime;

            if (colors[index] == prev)
            {
                int takeMin = min(neededTime[index], time);
                minTime = takeMin + solve(solve, index - 1, colors[index], max(neededTime[index], time));
            }

            else
            {
                minTime = solve(solve, index - 1, colors[index], neededTime[index]);
            }

            return dp[index] = minTime;
        };

        return solve(solve, n - 1, '$', neededTime[n - 1]);
    }
};



class Solution {
public:

    int solve (int index, char prev, int time, string &colors, vector<int>& neededTime, vector<int> &dp)
    {
        if (index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int minTime;

        if (colors[index] == prev)
        {
            int takeMin = min(neededTime[index], time);
            minTime = takeMin + solve(index - 1, colors[index], max(neededTime[index], time), colors, neededTime, dp);
        }
        
        else
        {
            minTime = solve(index - 1, colors[index], neededTime[index], colors, neededTime, dp);
        }

        return dp[index] = minTime;
    }

    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        vector<int> dp(n, -1);

        return solve(n - 1, '$', neededTime[n - 1], colors, neededTime, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        vector<int> dp(n + 1, 0);
        char prev = '$';
        int time = 0;

        for (int index = 1; index <= n; index++)
        {
            int minTime;

            if (colors[index - 1] == prev)
            {
                int takeMin = min(neededTime[index - 1], time);
                minTime = takeMin + dp[index - 1];
                time = max(neededTime[index - 1], time);
            }

            else
            {
                minTime = dp[index - 1];
                time = neededTime[index - 1];
            }

            dp[index] = minTime;
            prev = colors[index - 1];
        }
        
        return dp[n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        char prevChar = '$';
        int time = 0, dp = 0;

        for (int index = 1; index <= n; index++)
        {
            int minTime;

            if (colors[index - 1] == prevChar)
            {
                int takeMin = min(neededTime[index - 1], time);
                minTime = takeMin + dp;
                time = max(neededTime[index - 1], time);
            }

            else
            {
                minTime = dp;
                time = neededTime[index - 1];
            }

            dp = minTime;
            prevChar = colors[index - 1];
        }

        return dp;
    }
};