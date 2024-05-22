//Problem Link :- https://leetcode.com/problems/palindrome-partitioning/

// Solved by Backtracking
// Time Complexity :- O(n * 2^n)
// Space Complexity :- O(n)

class Solution {
public:

    bool isPalindrome (string &s)
    {
        string t = s;
        reverse (t.begin(), t.end());

        return (s == t);
    }

    void solve (int index, vector<string> &path, vector<vector<string>> &pal, string &s)
    {
        if (index == s.length())
        {
            pal.emplace_back(path);
            return;
        }

        for (int pos = index; pos < s.length(); pos++)
        {
            string t = s.substr(index, pos - index + 1);

            if (isPalindrome(t))
            {
                path.emplace_back(t);
                solve (pos + 1, path, pal, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<string> path;
        vector<vector<string>> pal;

        solve (0, path, pal, s);

        return pal;
    }
};


// Solved by Dynamic Programming
// Time Complexity :- O(2^n)
// Space Complexity :- O(n^2)
class Solution {
public:

    void solve (int start, vector<string> &path, vector<vector<string>> &pal, vector<vector<bool>> &dp, string &s)
    {
        if (start == s.length())
        {
            pal.emplace_back(path);
            return;
        }

        for (int end = start; end < s.length(); end++)
        {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;
                string t = s.substr (start, end - start + 1);
                path.emplace_back(t);
                solve (end + 1, path, pal, dp, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<string> path;
        vector<vector<string>> pal;
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        solve (0, path, pal, dp, s);

        return pal;
    }
};