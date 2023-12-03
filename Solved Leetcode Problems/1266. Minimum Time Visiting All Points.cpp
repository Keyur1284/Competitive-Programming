// Problem Link :- https://leetcode.com/problems/minimum-time-visiting-all-points/

// Solved by Brute Force Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int n = points.size(), time = 0;

        for (int i = 1; i < n; i++)
        {
            time += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        
        return time;
    }
};