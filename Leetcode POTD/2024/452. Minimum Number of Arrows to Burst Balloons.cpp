// Problem Link :- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size(), arrows = 0;
        sort (points.begin(), points.end());

        for (int i = 0; i < n; arrows++, i++)
        {
            int end = points[i][1];

            while (i + 1 < n && points[i + 1][0] <= end)
            {
                end = min(end, points[i + 1][1]);
                i++;
            }
        }

        return arrows;
    }
};