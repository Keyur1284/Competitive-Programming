// Problem Link :- https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// Solved by Two Pointer Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n = s.length(), m = t.length(), i = 0, j = 0;

        while (i < n && j < m)
        {
            if (s[i] == t[j])
                j++;

            i++;
        }

        return m - j;
    }
};