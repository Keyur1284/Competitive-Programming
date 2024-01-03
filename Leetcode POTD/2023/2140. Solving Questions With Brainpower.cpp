// Problem Link :- https://leetcode.com/problems/solving-questions-with-brainpower/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by Memoization Method

class Solution {
public:

    long long solve (int index, vector<vector<int>>& questions, vector<long long>& dp)
    {
        if (index >= questions.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        long long take = questions[index][0] + solve(index + questions[index][1] + 1, questions, dp);
        long long notTake = solve(index + 1, questions, dp);

        return dp[index] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();

        vector<long long> dp (n + 1, -1);

        return solve (0, questions, dp);
    }
};


// Solved by Tabulation Method

class Solution {
public:

    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();

        vector<long long> dp (n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            long long notTake = dp[index + 1];
            long long take = questions[index][0];

            if (index + questions[index][1] + 1 < n)
                take += dp[index + questions[index][1] + 1];

            dp[index] = max(take, notTake);
        }

        return dp[0];
    }
};