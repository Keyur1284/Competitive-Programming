// Problem Link :- https://leetcode.com/problems/reverse-prefix-of-word/

// Solved by Brute Force Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.length();

        for (int i = 0; i < n; i++)
        {
            if (word[i] == ch)
            {
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }

        return word;
    }
};