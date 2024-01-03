// Problem Link :- https://leetcode.com/problems/decoded-string-at-index/

// Solved by traversing from the end of the string and keeping track of the length of the decoded string.
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string decodeAtIndex(string s, int k) {

        long long len = 0;

        for (auto &it : s)
        {   
            if (isdigit(it))
                len *= it - '0';

            else
                len++;
        }

        int n = s.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if (isdigit(s[i]))
            {
                len /= s[i] - '0';
                k %= len;
            }

            else
            {
                if (k == 0 || k == len)
                    return string(1, s[i]);

                len--;
            }
        }

        return "";
    }
};