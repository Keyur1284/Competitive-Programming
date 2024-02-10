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
                if (s[left] == s[right] && (right - left <= 1 || dp[left + 1][right - 1]))
                    dp[left][right] = 1;

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



// Solved by Manacher's Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        string st = string(2 * n + 1, '!');

        for (int i = 0; i < n; i++)
        {
            st[2 * i + 1] = s[i];
        }

        vector<int> pal(2 * n + 1, 0);
        int center = 0, right = 0, count = 0;

        for (int i = 0; i < 2 * n + 1; i++)
        {
            int mirror = 2 * center - i;

            if (right - i > 0)
            {
                pal[i] = min(right - i, pal[mirror]);
            }

            int l = i - pal[i] - 1;
            int r = i + pal[i] + 1;

            while (l >= 0 && r < 2 * n + 1 && st[l] == st[r])
            {
                l--;
                r++;
                pal[i]++;
            }

            if (i + pal[i] > right)
            {
                center = i;
                right = i + pal[i];
            }

            count += (pal[i] + 1)/2;
        }

        return count;
    }
};