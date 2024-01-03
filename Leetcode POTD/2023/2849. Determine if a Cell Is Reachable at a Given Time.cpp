// Problem Link :- https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

// Solved using Maths
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int width = abs(sx - fx), height = abs(sy - fy);

        if (width == 0 && height == 0 && t == 1)
            return false;
        
        return t >= max(width, height);
    }
};