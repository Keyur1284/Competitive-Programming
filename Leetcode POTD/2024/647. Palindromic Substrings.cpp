// Problem Link :- https://leetcode.com/problems/palindromic-substrings/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        function<int(int, int)> solve = [&](int left, int right) -> int {

            if (left >= right)
                return 1;

            if (dp[left][right] != -1)
                return dp[left][right];

            return dp[left][right] = (s[left] == s[right]) ? solve(left + 1, right - 1) : 0;
        };

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                count += solve(i, j);
            }
        }

        return count;
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        int count = 0;

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = left; right < n; right++)
            {
                if (left == right)
                    dp[left][right] = 1;

                else if (left + 1 == right)
                    dp[left][right] = (s[left] == s[right]);

                else 
                    dp[left][right] = (s[left] == s[right]) ? dp[left + 1][right - 1] : 0;

                count += dp[left][right];
            }
        }

        return count;
    }
};



// Solved by Expand Around Center Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += expandAroundCenter(s, i, i);
            count += expandAroundCenter(s, i, i + 1);
        }

        return count;
    }

    int expandAroundCenter(string s, int left, int right)
    {
        int count = 0, n = s.length();

        while (left >= 0 && right < n && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }

        return count;
    }
};