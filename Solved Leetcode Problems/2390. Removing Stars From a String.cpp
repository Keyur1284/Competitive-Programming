// Problem Link :- https://leetcode.com/problems/removing-stars-from-a-string/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;

        for (auto &c : s)
        {
            if (c == '*')
                st.pop();

            else
                st.emplace(c);
        }

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


class Solution {
public:
    string removeStars(string s) {
        
        string ans = "";

        for (auto &c : s)
        {
            if (c == '*')
                ans.pop_back();

            else
                ans.push_back(c);
        }

        return ans;
    }
};


class Solution {
public:
    string removeStars(string s) {

        int n = s.size();
        vector<char> ch(n);
        
        string ans = "";

        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
                j--;

            else
                ch[j++] = s[i];
        }

        for (int i = 0; i < j; i++)
            ans.push_back(ch[i]);

        return ans;
    }
};