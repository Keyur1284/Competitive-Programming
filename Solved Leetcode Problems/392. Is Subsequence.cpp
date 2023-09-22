// Problem Link :- https://leetcode.com/problems/is-subsequence/

// Solved by traversing string
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length(), m = t.length();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (s[i] == t[j])
                i++;

            j++;
        }

        return (i == n);
    }
};