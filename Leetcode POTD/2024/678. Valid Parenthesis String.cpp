// Problem Link :- https://leetcode.com/problems/valid-parenthesis-string/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        function<int(int, int)> solve = [&](int index, int count) -> int
        {
            if (count < 0)
                return 0;

            if (index == n)
                return count == 0;

            if (dp[index][count] != -1)
                return dp[index][count];

            int isValid = 0;

            if (s[index] == '(' || s[index] == '*')
                isValid |= solve(index + 1, count + 1);

            if (s[index] == ')' || s[index] == '*')
                isValid |= solve(index + 1, count - 1);

            if (s[index] == '*')
                isValid |= solve(index + 1, count);

            return dp[index][count] = isValid;
        };

        return solve(0, 0);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        dp[n][0] = true;
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int count = 0; count < n; count++)
            {
                bool isValid = false;

                if (s[index] == '(' || s[index] == '*')
                    isValid |= dp[index + 1][count + 1];

                if ((s[index] == ')' || s[index] == '*') && count > 0)
                    isValid |= dp[index + 1][count - 1];

                if (s[index] == '*')
                    isValid |= dp[index + 1][count];

                dp[index][count] = isValid;
            }
        }

        return dp[0][0];
    }
};



// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool checkValidString(string s) {

        stack<int> open, star;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                open.emplace(i);
            
            else if (s[i] == '*')
                star.emplace(i);
            
            else
            {
                if (!open.empty())
                    open.pop();
                
                else if (!star.empty())
                    star.pop();
                
                else
                    return false;
            }
        }

        while (!open.empty() && !star.empty())
        {
            if (open.top() > star.top())
                return false;
                
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};



// Solved using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool checkValidString(string s) {

        int left = 0, right = 0, n = s.length();

        for (int i = 0; i < n; i++)
        {
            left += (s[i] == '(' || s[i] == '*') ? 1 : -1;
            right += (s[n - i - 1] == ')' || s[n - i - 1] == '*') ? 1 : -1;

            if (left < 0 || right < 0)
                return false;
        }

        return true;
    }
};