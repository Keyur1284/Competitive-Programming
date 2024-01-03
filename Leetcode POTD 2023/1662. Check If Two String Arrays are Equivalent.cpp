// Problem Link :- https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// Solved by Concatenating the strings and comparing them
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1, s2;

        for (auto &it : word1)
            s1 += it;
        
        for (auto &it : word2)
            s2 += it;

        return (s1 == s2);
    }
};



// Solved by two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0, j = 0, k = 0, l = 0, n = word1.size(), m = word2.size();
        
        while (i < n && j < m) 
        {
            
            if (word1[i][k++] != word2[j][l++])
                return false;
            
            if (k == word1[i].size()) 
            {
                i++;
                k = 0;
            }
            
            if (l == word2[j].size()) 
            {
                j++;
                l = 0;
            }
        }
        
        return (i == n && j == m);
    }
};