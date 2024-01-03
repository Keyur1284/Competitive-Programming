// Problem Link :- https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

// Solved by counting frequency 
// Time Complexity :- O(n * k)  n = number of words
// Space Complexity :- O(1)     k = average length of a word

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        vector<int> freq(26, 0);

        for (auto &word : words)
        {
            for (auto &c : word)
                freq[c - 'a']++;
        }

        for (auto &it : freq)
        {
            if (it % n)
                return false;
        }

        return true;
    }
};