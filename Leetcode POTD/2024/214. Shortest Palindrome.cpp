// Problem Link :- https://leetcode.com/problems/shortest-palindrome/

// Solved by Two Pointers
// Time Complexity :- O(n ^ 2)
// Space Complexity :- O(n)

class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.length();

        if (n == 0)
            return s;

        int left = 0;

        for (int right = n - 1; right >= 0; right--)
        {
            if (s[right] == s[left])
                left++;
        }

        if (left == n)
            return s;

        string nonPalindromeSuffix = s.substr(left);
        string reverseSuffix = string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        return reverseSuffix + shortestPalindrome(s.substr(0, left)) + nonPalindromeSuffix;
    }
};



// Solved by KMP Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.length();

        if (n == 0)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;

        int m = comb.length();
        vector<int> lps(m, 0);

        for (int i = 1; i < m; i++)
        {
            int j = lps[i - 1];

            while (j && comb[i] != comb[j])
                j = lps[j - 1];

            if (comb[i] == comb[j])
                j++;

            lps[i] = j;
        }

        int palLen = lps[m - 1];
        string nonPalindromeSuffix = s.substr(palLen);
        string reverseSuffix = string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        return reverseSuffix + s;
    }
};



// Solved by Rolling Hash
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.length();
        long long hashBase = 29, modValue = 1e9 + 7, forwardHash = 0, reverseHash = 0, powerValue = 1;
        int palindromeEndIndex = -1;

        for (int i = 0; i < n; ++i)
        {
            char currentChar = s[i];

            forwardHash = (forwardHash * hashBase + (currentChar - 'a' + 1)) % modValue;
            reverseHash = (reverseHash + (currentChar - 'a' + 1) * powerValue) % modValue;
            powerValue = (powerValue * hashBase) % modValue;

            if (forwardHash == reverseHash)
                palindromeEndIndex = i;
        }

        string suffix = s.substr(palindromeEndIndex + 1);
        string reversedSuffix(suffix.rbegin(), suffix.rend());

        return reversedSuffix + s;
    }
};



// Solved by Manacher's Algorithm   (Modified)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.length();

        if (n == 0)
            return s;

        string st = string(2 * n + 1, '!');

        for (int i = 0; i < n; i++)
        {
            st[2 * i + 1] = s[i];
        }

        vector<int> pal(2 * n + 1, 0);
        int longestLength = 0, center = 0, right = 0;

        for (int i = 0; i < 2 * n + 1; i++)
        {
            int mirror = 2 * center - i;

            if (right - i > 0)
                pal[i] = min(right - i, pal[mirror]);

            int l = i - pal[i] - 1;
            int r = i + pal[i] + 1;

            while (l >= 0 && r < 2 * n + 1 && st[l] == st[r])
            {
                pal[i]++;
                l--;
                r++;
            }

            if (i + pal[i] > right)
            {
                center = i;
                right = i + pal[i];
            }

            // Update the longest palindrome length starting at beginning
            if (i == pal[i])
                longestLength = pal[i];
        }

        string nonPalindromeSuffix = s.substr(longestLength);
        string reverseSuffix = string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        return reverseSuffix + s;
    }
};