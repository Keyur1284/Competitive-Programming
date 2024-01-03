// Problem Link :- https://leetcode.com/problems/longest-palindromic-substring/

// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:

    void expand (int left, int right, int &n, string &ans, string &s)
    {
        while (left >= 1 && right <= n && s[left] == s[right])
        {
            left--;
            right++;
        }

        int len = right - left - 1;

        if (ans.size() < len)
            ans = s.substr(left + 1, len); 
    }

    string longestPalindrome(string s) {
        
        int n = s.size();
        s = '!' + s;
        string ans = "";

        for (int i = 1; i <= n; i++)
        {
            expand(i, i, n, ans, s);
            expand(i, i + 1, n, ans, s);
        }

        return ans;
    }
};


// Solved by Manacher's Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        string st = string(2 * n + 1, '!');

        for (int i = 0; i < n; i++)
        {
            st[2 * i + 1] = s[i];
        }

        vector<int> pal(2 * n + 1, 0);
        int longestLength = 0, longestCenter = 0, center = 0, right = 0;

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

            if (pal[i] >= longestLength)
            {
                longestLength = pal[i];
                longestCenter = i;
            }

            if (i + pal[i] > right)
            {
                center = i;
                right = i + pal[i];
            }
        }

        string ans = "";

        for (int index = longestCenter - longestLength + 1; index < longestCenter + longestLength; index += 2)
            ans += st[index];

        return ans;
    }
};
