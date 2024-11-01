// Problem Link :- https://leetcode.com/problems/delete-characters-to-make-fancy-string/

// Solved by traversing the string
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.length();

        if (n < 3)
            return s;

        string fancyString;

        for (int i = 0; i + 2 < n; i++)
        {
            if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
                continue;

            fancyString += s[i];
        }

        fancyString += s[n - 2];
        fancyString += s[n - 1];

        return fancyString;
    }
};