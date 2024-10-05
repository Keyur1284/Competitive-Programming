// Problem Link :- https://leetcode.com/problems/permutation-in-string/

// Solved by Sliding Window
// Time Complexity :- O(n + 26 * (m - n))   n = s1.length()
// Space Complexity :- O(26 + 26) = O(1)    m = s2.length()

class Solution {
    
    bool areVectorsEqual(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i]) 
                return false;
        }
        
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length(), m = s2.length();

        if (m < n) 
            return false;
        
        vector<int> freqS1(26, 0);
        
        for (char c : s1) 
            freqS1[c - 'a']++;
        
        vector<int> freqS2(26, 0);
        int i = 0, j = 0;
        
        while (j < m)
        {
            freqS2[s2[j] - 'a']++;
            
            if (j - i + 1 == n && areVectorsEqual(freqS1, freqS2)) 
                return true;
            
            if (j - i + 1 == n)
                freqS2[s2[i++] - 'a']--;

            j++;
        }

        return false;
    }
};