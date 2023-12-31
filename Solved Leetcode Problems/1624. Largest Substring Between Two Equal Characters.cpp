// Problem Link :- https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Solved by string traversal
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        int maxLen = -1, n = s.length();
        vector<int> pos(26, -1);

        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';

            if (pos[index] != -1)
            {
                int len = i - pos[index] - 1;
                maxLen = max(maxLen, len);
            }

            else
                pos[index] = i;
        }

        return maxLen;
    }
};