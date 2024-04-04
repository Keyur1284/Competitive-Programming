// Problem Link :- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// Solved by traversing the string
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxDepth(string s) {
        
        int maxDepth = 0, depth = 0;

        for (auto &it : s)
        {
            if (it == '(')
                depth++;

            else if (it == ')')
                depth--;

            maxDepth = max(depth, maxDepth);
        }

        return maxDepth;
    }
};