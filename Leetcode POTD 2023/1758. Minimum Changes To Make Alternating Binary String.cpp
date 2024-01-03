// Problem Link :- https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

// Solved by brute force approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length(), start0 = 0, start1 = 0;
        
        for (int i = 0; i < n; i++) 
        {
            if (i % 2 == 0) 
            {
                (s[i] == '0') ? start1++ : start0++;
            } 
            
            else 
            {
                (s[i] == '1') ? start1++ : start0++;
            }
        }
        
        return min(start0, start1);
    }
};



class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length(), start0 = 0;
        
        for (int i = 0; i < n; i++) 
        {
            if (i % 2 == 0) 
            {
                if (s[i] == '1')
                    start0++;
            } 
            
            else 
            {
                if (s[i] == '0')
                    start0++;
            }
        }
        
        return min(start0, n - start0);
    }
};