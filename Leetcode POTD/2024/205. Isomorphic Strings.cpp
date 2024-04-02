// Problem Link :- https://leetcode.com/problems/isomorphic-strings/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(26)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.length(), m = t.length();

        if (n != m) 
            return false;

        unordered_map<char, char> mpS, mpT;

        for (int i = 0; i < n; i++)
        {
            if (mpS.find(s[i]) == mpS.end() && mpT.find(t[i]) == mpT.end())
            {
                mpS[s[i]] = t[i];
                mpT[t[i]] = s[i];
            }
            
            else if (mpS[s[i]] != t[i] || mpT[t[i]] != s[i])
                return false;
        }

        return true;
    }
};



class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.length(), m = t.length();

        if (n != m) 
            return false;

        unordered_map<char, char> mpS, mpT;
        
        for (int i = 0; i < n; ++i) 
        {
            if (mpS[s[i]] != mpT[t[i]])
                return false;

            mpS[s[i]] = i + 1;
            mpT[t[i]] = i + 1;
        }
        
        return true;
    }
};