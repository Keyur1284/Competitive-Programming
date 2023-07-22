// Problem Link :- https://leetcode.com/problems/knight-probability-in-chessboard/

// Solved by DP 
// Time Complexity : O(N^2 * K * 8)
// Space Complexity : O(N^2 * K)

class Solution {
public:
    
    vector<pair<int, int>> moves = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    bool isValid (int x, int y, int n)
    {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    double solve (int x, int y, int n, int steps, unordered_map<string, double> &dp)
    {
        if (steps == 0)
            return 1;

        string key = to_string(x) + " " + to_string(y) + " " + to_string(steps);

        if (dp.find(key) != dp.end())
            return dp[key];

        double prob = 0;

        for (auto &it : moves)
        {
            int newx = x + it.first, newy = y + it.second;

            if (isValid(newx, newy, n))
            {
                prob += solve (newx, newy, n, steps - 1, dp)/8.0;
            }
        }

        return dp[key] = prob;
    } 

    double knightProbability(int n, int k, int row, int column) {

        unordered_map<string, double> dp;

        return solve (row, column, n, k, dp);
    }
};