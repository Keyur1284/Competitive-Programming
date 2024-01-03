// Problem Link :- https://leetcode.com/problems/backspace-string-compare/

// Solved by making copy of string
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    string findString (string &s)
    {
        string copy = "";

        for (auto &it : s)
        {
            if (it == '#')
            {
                if (copy.length())
                    copy.pop_back();
            }

            else
                copy += it;
        }

        return copy;
    }

    bool backspaceCompare(string s, string t) {
        
        string copys = findString (s);
        string copyt = findString (t);

        return (copys == copyt);
    }
};



// Solved by using two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = s.length() - 1, j = t.length() - 1, skip;

        while (true)
        {
            skip = 0;

            while (i >= 0 && (skip || s[i] == '#'))
            {
                skip += (s[i--] == '#') ? 1 : -1;
            }

            skip = 0;

            while (j >= 0 && (skip || t[j] == '#'))
            {
                skip += (t[j--] == '#') ? 1 : -1;
            }

            if (i >= 0 && j >= 0 && s[i] == t[j])
            {
                i--;
                j--;
            }

            else
                break;
        }

        return (i == -1 && j == -1);
    }
};