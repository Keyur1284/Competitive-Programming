// Problem Link :- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int add = 0;
        
        for (auto ch : s)
        {
            if(ch == '(')
                st.emplace(ch);
            
            else if (!st.empty())
                st.pop();
            
            else
                add++;
        }
        
        return add + st.size();
    }
};



// Solved using two variables
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count = 0, add = 0;

        for (auto ch : s)
        {
            if (ch == '(')
                count++;

            else if (count)
                count--;

            else
                add++;
        }

        return add + count;
    }
};