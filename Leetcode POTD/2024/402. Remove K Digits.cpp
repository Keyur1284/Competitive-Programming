// Problem Link :- https://leetcode.com/problems/remove-k-digits/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string removeKdigits(string s, int k) {
        
        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > s[i] && k)
            {
                st.pop();
                k--;
            }

            if (s[i] == '0' && st.empty())
                continue;

            else
                st.emplace(s[i]);
        }

        while (!st.empty() && k)
        {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string ans = "";

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};