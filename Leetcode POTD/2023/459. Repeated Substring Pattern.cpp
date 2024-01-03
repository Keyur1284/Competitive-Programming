// Problem Link :- https://leetcode.com/problems/repeated-substring-pattern/

// Solved by Bruce Force Approach
// Time Complexity :- O(n^1.5)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (string &pat, string &s)
    {
        int count = s.length()/pat.length();
        string t = "";

        while(count--)
            t += pat;

        return (t == s);
    }

    bool repeatedSubstringPattern(string s) {
        
        int len = s.length();
        string pat = "";

        for (int i = 0; i < len; i++)
        {
            pat += s[i];

            if (len % pat.size() == 0 && pat != s)
            {
                if (check(pat, s))
                    return true;
            }
        }

        return false;
    }
};  



// Solved by Miscellaneous Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string t = s + s;
        string p = t.substr(1, t.size() - 2);

        if (p.find(s) != -1)
            return true;

        return false;
    }
};
    