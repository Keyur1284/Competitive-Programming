// Problem Link :- https://leetcode.com/problems/find-the-difference/

// Solved by traversing
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int diff = 0, len = s.length();

        for (int i = 0; i < len; i++)
        {
            diff += t[i] - s[i];
        }

        diff += t[len];

        return (char)diff;
    }
};