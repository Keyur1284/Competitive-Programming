// Problem Link :- https://leetcode.com/problems/extra-characters-in-a-string/

// Solved by Memoization Method
// Time Complexity :- O(n^2) {If we use substr function then it will take O(n) time to create a substring, so total time complexity will be O(n^3)}
// Space Complexity :- O(n + m * k)     n = length of string, m = average length of words, k = number of words

class Solution {
public:

    int func (int index, int &n, vector<int> &dp, unordered_set<string> &dict,  string &s)
    {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int ans = INT_MAX;

        for (int len = 1; index + len <= n; len++)
        {
            string temp = s.substr(index, len);

            if (dict.find(temp) != dict.end())
            {
                ans = min(ans, func(index + len, n, dp, dict, s));
            }
        }

        ans = min(ans, 1 + func(index + 1, n, dp, dict, s));

        return dp[index] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp (n, -1);

        return func (0, n, dp, dict, s);
    }
};



class Solution {
public:

    int func (int index, int &n, vector<int> &dp, unordered_set<string> &dict,  string &s)
    {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int ans = INT_MAX;
        string temp = "";

        for (int len = 1; index + len <= n; len++)
        {
            temp += s[index + len - 1];

            if (dict.find(temp) != dict.end())
            {
                ans = min(ans, func(index + len, n, dp, dict, s));
            }
        }

        ans = min(ans, 1 + func(index + 1, n, dp, dict, s));

        return dp[index] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp (n, -1);

        return func (0, n, dp, dict, s);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n + m * k)     n = length of string, m = average length of words, k = number of words

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp (n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int ans = INT_MAX;
            string temp = "";

            for (int len = 1; index + len <= n; len++)
            {
                temp += s[index + len - 1];

                if (dict.find(temp) != dict.end())
                {
                    ans = min(ans, dp[index + len]);
                }
            }

            ans = min(ans, 1 + dp[index + 1]);
            dp[index] = ans;
        }

        return dp[0];
    }
};