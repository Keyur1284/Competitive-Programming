// Problem Link :- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.emplace(i);

            else if (s[i] == ')')
            {
                if (!st.empty())
                    st.pop();

                else
                    s[i] = '*';
            }
        }

        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }

        // s.erase(remove(s.begin(), s.end(), '*'), s.end());


        string valid;

        for (auto &it : s)
        {
            if (it != '*')
                valid += it;
        }

        return valid;
    }
};