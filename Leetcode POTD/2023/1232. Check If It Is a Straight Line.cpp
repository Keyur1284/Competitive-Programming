// Problem Link :- https://leetcode.com/problems/check-if-it-is-a-straight-line/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        int delX = (coordinates[1][0] - coordinates[0][0]);
        int delY = (coordinates[1][1] - coordinates[0][1]);
        
        for (int i = 2; i < n; i++)
        {
            int deltaY = (coordinates[i][1] - coordinates[i - 1][1]);
            int deltaX = (coordinates[i][0] - coordinates[i - 1][0]);

            if (delX * deltaY != delY * deltaX)
                return false;
        }

        return true;
    }
};