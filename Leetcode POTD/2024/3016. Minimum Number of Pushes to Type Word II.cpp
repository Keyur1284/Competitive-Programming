// Problem Link :- https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

// Solved by sorting freq of characters
// Time Complexity :- O(n + 26log26) = O(n)
// Space Complexity :- O(26) = O(1)

class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26, 0);

        for (auto &it : word)
            freq[it - 'a']++;

        sort (freq.rbegin(), freq.rend());

        int pushes = 0;

        for (int i = 0; i < 26; i++)
        {
            if (!freq[i])
                break;

            pushes += freq[i] * (i / 8 + 1);
        }

        return pushes;
    }
};