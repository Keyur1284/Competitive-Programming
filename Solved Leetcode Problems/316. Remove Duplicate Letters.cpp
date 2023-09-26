// Problem Link :- https://leetcode.com/problems/remove-duplicate-letters/

// This problem is same as "Smallest Subsequence of Distinct Characters"
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

// Solved by using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string removeDuplicateLetters(string s) {

        int len = s.length();
        vector<int> lastInd (26);

        for (int i = 0; i < len; i++)
            lastInd[s[i] - 'a'] = i;

        vector<bool> vis(26, false);
        stack<char> st;

        for (int i = 0; i < len; i++)
        {
            if (vis[s[i] - 'a'])
                continue;

            while (!st.empty() && st.top() > s[i] && i < lastInd[st.top() - 'a'])
            {
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.emplace(s[i]);
            vis[s[i] - 'a'] = true;
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