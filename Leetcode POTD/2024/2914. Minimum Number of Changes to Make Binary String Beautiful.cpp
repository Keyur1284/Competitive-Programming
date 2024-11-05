// Problem Link :- https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length(), changes = 0;

        for (int i = 0; i < n; i += 2)
        {
            changes += (s[i] != s[i + 1]);
        }

        return changes;
    }
};