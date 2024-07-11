// Problem Link :- https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Solved using stack
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.emplace(i);

            else if (s[i] == ')')
            {
                int j = st.top();
                st.pop();
                reverse(s.begin() + j, s.begin() + i);
            }
        }

        string ans = "";

        for (auto &ch : s)
        {
            if (ch == '(' || ch == ')')
                continue;

            ans += ch;
        }

        return ans;
    }
};



// Solved by Wormhole Teleportation Technique
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        
        int n = s.length();
        stack<int> openParenthesesIndices;
        vector<int> pair(n);

        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == '(')
                openParenthesesIndices.push(i);
            
            if (s[i] == ')') 
            {
                int j = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string result;
        
        for (int currIndex = 0, direction = 1; currIndex < n; currIndex += direction) 
        {
            if (s[currIndex] == '(' || s[currIndex] == ')') 
            {
                currIndex = pair[currIndex];
                direction = -direction;
            } 
            
            else
                result += s[currIndex];
        }
        
        return result;
    }
};