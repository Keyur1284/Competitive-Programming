// Problem Link :- https://leetcode.com/problems/merge-strings-alternately/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string ans = "";
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;

        while (i < m || j < n)
        {
            if (i < m)
                ans += word1[i++];
                

            if (j < n)
                ans += word2[j++];
        }

        return ans; 
    }
};