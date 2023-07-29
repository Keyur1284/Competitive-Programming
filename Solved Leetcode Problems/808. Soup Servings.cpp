// Problem Link :- https://leetcode.com/problems/soup-servings/

// Solved by DP + Maths
// Time Complexity :- O(N^2)
// Space Complexity :- O(N^2)

class Solution {
public:

    vector<pair<int, int>> ways = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};

    double serveSoup (int a, int b, vector<vector<double>> &dp)
    {
        if (a <= 0 && b <= 0)
            return 0.5;

        if (a <= 0)
            return 1.0;

        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        double curr = 0.0;

        for (auto &it : ways)
        {
            int newa = a - it.first, newb = b - it.second;
            curr += 0.25 * serveSoup(newa, newb, dp);
        }

        return dp[a][b] = curr;
    }

    double soupServings(int n) {
        
        if (n >= 5000)
            return 1.0;

        n = (n + 24)/25;

        vector<vector<double>> dp (n + 1, vector<double> (n + 1, -1.0));
        return serveSoup (n, n, dp);
    }
};