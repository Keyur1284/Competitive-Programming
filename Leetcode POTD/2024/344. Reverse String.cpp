// Problem Link :- https://leetcode.com/problems/reverse-string/

// Solved by Swapping
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();

        for (int i = 0; i < n/2; i++)
            swap(s[i], s[n - i - 1]);
    }
};



// Solved by Reversing
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        reverse(s.begin(), s.end());
    }
};