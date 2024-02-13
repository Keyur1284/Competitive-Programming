// Problem Link :- https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Solved by reversing the string
// Time Complexity :- O(n * m)  n = number of strings
// Space Complexity :- O(m)     m = maximum length of string

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for (auto &it : words)
        {
            string s = it;
            reverse(s.begin(), s.end());

            if (s == it)
                return it;
        }

        return "";
    }
};



// Solved by using two pointers
// Time Complexity :- O(n * m)  n = number of strings
// Space Complexity :- O(1)     m = maximum length of string

class Solution {
public:

    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        
        for (auto &it : words)
        {
            if (isPalindrome(it))
                return it;
        }

        return "";
    }
};