// Problem Link :- https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort (points.begin(), points.end());
        int n = points.size(), maxWidth = 0;

        for (int i = 1; i < n; i++)
        {
            int width = points[i][0] - points[i - 1][0];
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
};