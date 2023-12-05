// Problem Link :- https://leetcode.com/problems/count-of-matches-in-tournament/

// Solved by Simulating
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        
        int matches = 0;

        while (n != 1)
        {
            matches += n/2;
            n = n/2 + (n & 1);
        }

        return matches;
    }
};



// Solved by Recursion
// Time Complexity :- O(logn)
// Space Complexity :- O(logn)

class Solution {
public:
    int numberOfMatches(int n) {
        
        if (n == 1)
            return 0;
        
        return n/2 + numberOfMatches(n/2 + (n & 1));
    }
};



// Solved by Logic
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        
        return n - 1;
    }
};