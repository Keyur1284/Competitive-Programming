// Problem Link :- https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Solved by traversing string
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.size(), temp = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                (i < n/2)? temp++ : temp--;
            }
        }

        return (temp == 0);
    }
};