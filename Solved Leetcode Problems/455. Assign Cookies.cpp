// Problem Link :- https://leetcode.com/problems/assign-cookies/

// Solved by Sorting and Two Pointer Approach
// Time Complexity :- O(nlogn + mlogm)
// Space Complexity :- O(logn + logm)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int n = g.size(), m = s.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int contentChildren = 0, cookieIndex = 0;

        while (cookieIndex < m && contentChildren < n) 
        {
            if (s[cookieIndex] >= g[contentChildren])
                contentChildren++;

            cookieIndex++;
        }

        return contentChildren;
    }
};