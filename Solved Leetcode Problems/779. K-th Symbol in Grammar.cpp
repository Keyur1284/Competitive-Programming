// Problem Link :- https://leetcode.com/problems/k-th-symbol-in-grammar/

// Solved by Binary Search Tree Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int DFS (int n, int k, int val)
    {
        if (n == 1)
            return val;
        
        int nodes = (1 << (n - 1));

        if (k > nodes/2)
        {
            int nextVal = (val == 0) ? 1 : 0;
            return DFS (n - 1, k - nodes/2, nextVal);
        }

        else
        {
            int nextVal = (val == 0) ? 0 : 1;
            return DFS (n - 1, k, nextVal);
        }
    }

    int kthGrammar(int n, int k) {
        
        return DFS (n, k, 0);
    }
};



// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int DFS (int n, int k)
    {
        if (n == 1)
            return 0;
        
        int nodes = (1 << (n - 1));

        if (k > nodes/2)
        {
            return 1 - DFS (n - 1, k - nodes/2);
        }

        else
        {
            return DFS (n - 1, k);
        }
    }

    int kthGrammar(int n, int k) {
        
        return DFS (n, k);
    }
};



// Solved by Iterative Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int kthGrammar(int n, int k) {
        
        if (n == 1)
            return 0;

        int val = 1;

        for (int row = n; row > 1; row--)
        {
            int nodes = (1 << (row - 1));

            if (k > nodes/2)
            {
                val = 1 - val;
                k -= nodes/2;
            }
        }

        return (val == 0);
    }
};



// Solved by Math
// Time Complexity :- O(logk)
// Space Complexity :- O(1)

class Solution {
public:
    int kthGrammar(int n, int k) {
        
        int flip = __builtin_popcount(k - 1);
        return flip % 2;
    }
};