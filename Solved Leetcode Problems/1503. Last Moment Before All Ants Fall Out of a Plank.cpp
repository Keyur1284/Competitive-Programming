// Problem Link :- https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

// Solved by Simulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int maxTime = 0;

        for (auto &it : left)
            maxTime = max(maxTime, it);

        for (auto &it : right)
            maxTime = max(maxTime, n - it);

        return maxTime; 
    }
};