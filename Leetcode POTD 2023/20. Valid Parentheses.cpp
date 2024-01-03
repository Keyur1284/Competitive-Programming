// Problem Link :- https://leetcode.com/problems/valid-parentheses/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        
        for (auto &it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                st.emplace(it);

            else if (st.empty())
                return false;

            else
            {
                if (st.top() != mp[it])
                    return false;

                st.pop();
            }
        }

        return (st.empty());
    }
};