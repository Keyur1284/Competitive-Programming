// Problem Link :- https://leetcode.com/problems/first-unique-character-in-a-string/

// Solved by storing frequency of each character 
// Time Complexity :- O(n)
// Space Complexity :- O(26)

class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.length();
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++; 
        }

        for (int i = 0; i < n; i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};