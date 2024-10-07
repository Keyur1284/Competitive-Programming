// Problem Link :- https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;

        for (auto ch : s)
        {
            if (ch == 'B' && !st.empty() && st.top() == 'A' || ch == 'D' && !st.empty() && st.top() == 'C')
                st.pop();

            else
                st.emplace(ch);
        }

        return (int) st.size();
    }
};



// Solved using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minLength(string s) {
        
        int n = s.length(), writeIndex = 0;
        
        for (int readIndex = 0; readIndex < n; readIndex++)
        {
            if (s[readIndex] == 'B' && writeIndex > 0 && s[writeIndex - 1] == 'A' || s[readIndex] == 'D' && writeIndex > 0 && s[writeIndex - 1] == 'C')
                writeIndex--;
            
            else
                s[writeIndex++] = s[readIndex];
        }
        
        return writeIndex;
    }
};