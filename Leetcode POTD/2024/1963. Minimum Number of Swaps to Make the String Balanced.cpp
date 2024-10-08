// Problem Link :- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minSwaps(string s) {
        
        int swaps = 0;
        stack<char> st;

        for (auto ch : s)
        {
            if (ch == '[')
                st.emplace(ch);

            else if (!st.empty())
                st.pop();

            else
                swaps++;
        }

        return (swaps + 1) / 2;
    }
};



// Solved without using stack
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minSwaps(string s) {
        
        int stackSize = 0;

        for (auto ch : s)
        {
            if (ch == '[')
                stackSize++;

            else if (stackSize > 0)
                stackSize--;
        }

        return (stackSize + 1) / 2;
    }
};