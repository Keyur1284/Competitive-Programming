// Problem Link :- https://leetcode.com/problems/length-of-last-word/

// Solved by traversing the string from the end
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0, n = s.length(), i = n - 1;

        while (i >= 0 && s[i] == ' ')
            i--;

        while (i >= 0)
        {
            if (s[i] == ' ')
                break;

            i--, len++;
        }

        return len;
    }
};



class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0, n = s.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
                len++;

            else if (len)
                return len;
        }

        return len;
    }
};