// Problem Link :- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort (points.begin(), points.end());
        int arrows = 1, minEnd = INT_MAX;

        for (auto &point : points)
        {
            if (point[0] > minEnd)
            {
                arrows++;
                minEnd = point[1];
            }

            else
                minEnd = min(minEnd, point[1]);
        }

        return arrows;
    }
};



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



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort (points.begin(), points.end(), [&](const vector<int> &interval1, const vector<int> &interval2)
        {
            return interval1[1] < interval2[1];
        });
        
        int arrows = 1, end = points[0][1], n = points.size();

        for (int i = 1; i < n; i++)
        {
            if (points[i][0] > end)
            {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort (points.begin(), points.end(), [&](const vector<int> &interval1, const vector<int> &interval2)
        {
            return interval1[1] < interval2[1];
        });
        
        int arrows = 0;
        long end = LONG_MIN;

        for (auto &point : points)
        {
            if (point[0] > end)
            {
                arrows++;
                end = point[1];
            }
        }

        return arrows;
    }
};