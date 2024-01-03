// Problem Link :- https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// Solved by Memoization Method
// Time Complexity :- O(n^2 * d)
// Space Complexity :- O(n * d)

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp (n, vector<int> (d, -1));

        auto solve = [&](auto self, int index, int day)
        {
            if (index == n && day == d)
                return 0;

            if (index == n || day == d)
                return (int)1e9;

            if (dp[index][day] != -1)  
                return dp[index][day];

            int ans = 1e9, maxDiff = 0;

            for (int job = index; job < n; job++)
            {
                maxDiff = max(maxDiff, jobDifficulty[job]);
                int take = maxDiff + self(self, job + 1, day + 1);
                ans = min(ans, take);
            }

            return dp[index][day] = ans;
        };

        int minDiff = solve(solve, 0, 0);

        return (minDiff >= 1e9) ? -1 : minDiff;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2 * d)
// Space Complexity :- O(n * d)

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp (n + 1, vector<int> (d + 1));

        for (int index = n; index >= 0; index--)
        {
            for (int day = d; day >= 0; day--)
            {
                if (index == n && day == d)
                {
                    dp[index][day] = 0;
                    continue;
                }

                if (index == n || day == d)
                {
                    dp[index][day] = 1e9;
                    continue;
                }

                int ans = 1e9, maxDiff = 0;

                for (int job = index; job < n; job++)
                {
                    maxDiff = max(maxDiff, jobDifficulty[job]);
                    int take = maxDiff + dp[job + 1][day + 1];
                    ans = min(ans, take);
                }

                dp[index][day] = ans;
            }
        }

        return (dp[0][0] >= 1e9) ? -1 : dp[0][0];
    }
};



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp (d + 1, vector<int> (n + 1));

        for (int day = d; day >= 0; day--)
        {
            for (int index = n; index >= 0; index--)                
            {
                if (index == n && day == d)
                {
                    dp[day][index] = 0;
                    continue;
                }

                if (index == n || day == d)
                {
                    dp[day][index] = 1e9;
                    continue;
                }

                int ans = 1e9, maxDiff = 0;

                for (int job = index; job < n; job++)
                {
                    maxDiff = max(maxDiff, jobDifficulty[job]);
                    int take = maxDiff + dp[day + 1][job + 1];
                    ans = min(ans, take);
                }

                dp[day][index] = ans;
            }
        }

        return (dp[0][0] >= 1e9) ? -1 : dp[0][0];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2 * d)
// Space Complexity :- O(n)

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<int> dp(n + 1);

        for (int day = d; day >= 0; day--)
        {
            vector<int> temp(n + 1);

            for (int index = n; index >= 0; index--)
            {
                if (index == n && day == d)
                {
                    temp[index] = 0;
                    continue;
                }

                if (index == n || day == d)
                {
                    temp[index] = 1e9;
                    continue;
                }

                int ans = 1e9, maxDiff = 0;

                for (int job = index; job < n; job++)
                {
                    maxDiff = max(maxDiff, jobDifficulty[job]);
                    int take = maxDiff + dp[job + 1];
                    ans = min(ans, take);
                }

                temp[index] = ans;
            }

            dp = temp;
        }

        return (dp[0] >= 1e9) ? -1 : dp[0];
    }
};