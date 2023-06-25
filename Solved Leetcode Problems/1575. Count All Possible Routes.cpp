// Problem Link :- https://leetcode.com/problems/count-all-possible-routes/

// Solved by Memoization Method
// Time Complexity :- O(n^2 * fuel)
// Space Complexity :- O(n * fuel)

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve (vector<int>& locations, int &n, int start, int &finish, int fuel, vector<vector<int>> &dp)
    {
        if (fuel < 0)
            return 0;

        if (dp[start][fuel] != -1)
            return dp[start][fuel];

        int ways = (start == finish);

        for (int i = 0; i < n; i++)
        {
            if (i != start)
            {
                int reqFuel = abs(locations[start] - locations[i]);

                if (reqFuel <= fuel)
                {
                    ways += solve (locations, n, i, finish, fuel - reqFuel, dp);
                    ways %= MOD;
                }
            }
        }

        return dp[start][fuel] = ways;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n = locations.size();
        vector<vector<int>> dp (n, vector<int> (fuel + 1, -1));

        return solve (locations, n, start, finish, fuel, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2 * fuel)
// Space Complexity :- O(n * fuel)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n = locations.size();
        vector<vector<int>> dp (n, vector<int> (fuel + 1, 0));

        for (int k = 0; k <= fuel; k++)
            dp[finish][k] = 1;

        for (int k = 0; k <= fuel; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        int reqFuel = abs(locations[j] - locations[i]);

                        if (reqFuel <= k)
                        {
                            dp[i][k] += dp[j][k - reqFuel];
                            dp[i][k] %= MOD;
                        }
                    }
                }
            }
        } 

        return dp[start][fuel];       
    }
};