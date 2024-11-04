// Problem Link :- https://leetcode.com/problems/string-compression-iii/

// Solved by two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string compressedString(string word) {

        int n = word.length();
        string comp = "";
        int i = 0;

        while (i < n)
        {
            int j = i, count = 0;

            while (count < 9 && j < n && word[j] == word[i])
            {
                count++;
                j++;
            }

            comp += to_string(count) + word[i];
            i = j;
        }

        return comp;
    }
};