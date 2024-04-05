// Problem Link :- https://leetcode.com/problems/make-the-string-great/

// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string makeGood(string s) {
        
        stack<char> st;
        for (auto &ch : s)
        {
            if (!st.empty() && abs(st.top() - ch) == 'a' - 'A')
                st.pop();
            
            else
                st.emplace(c);
        }

        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};