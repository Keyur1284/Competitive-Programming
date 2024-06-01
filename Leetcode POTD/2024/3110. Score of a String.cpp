// Problem Link :- https://leetcode.com/problems/score-of-a-string/

// Solved by traversing string
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int scoreOfString(string s) {
        
        int diff = 0;
        int n = s.length();
        
        for (int i = 1; i < n; i++)
        {
            diff += abs(s[i] - s[i - 1]);
        }
        
        return diff;
    }
};