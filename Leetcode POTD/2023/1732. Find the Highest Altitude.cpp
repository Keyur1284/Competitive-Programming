// Problem Link :- https://leetcode.com/problems/find-the-highest-altitude/

// Solved by prefix sum
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maxAltitude = 0, altitude = 0;

        for (auto &it : gain)
        {
            altitude += it;
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};