// Problem Link :- https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

// Solved by Line Sweep Algorithm
// Time Complexity :- O(n + 1e6)
// Space Complexity :- O(1e6)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int minGroups = 0;
        vector<int> pref(1e6 + 2, 0);

        for (auto &interval : intervals)
        {
            pref[interval[0]]++;
            pref[interval[1] + 1]--;
        }

        for (int i = 1; i <= 1e6; i++)
        {
            pref[i] += pref[i - 1];
            minGroups = max(minGroups, pref[i]);
        }

        return minGroups;
    }
};