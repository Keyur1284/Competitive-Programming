// Problem Link :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Solved using inbuilt STL function
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {

        int index = haystack.find(needle);        
        return index;
    }
};


// Solved using Brute Force (Sliding Window Approach)
// Time Complexity :- O(n*m)
// Space Complexity :- O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (haystack[i] == needle[j])
                i++, j++;

            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        
        if (j == m)
            return i - j;

        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for (int start = 0; start <= n - m; start++)
        {
            for (int i = 0; i < m; i++)
            {
                if (needle[i] != haystack[start + i])
                    break;

                if (i == m - 1)
                    return start;
            }
        }

        return -1;
    }
};


// Solved using Rabin Karp Algorithm (Single Hash)
// Worst Case Time Complexity :- O(n*m)
// Best Case Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:
    
    int MOD = 1000000007;
    int radix = 26;

    int hashValue (string &s, int m)
    {
        long factor = 1;
        int value = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            value += ((s[i] - 'a') * factor) % MOD;
            factor = (factor * radix) % MOD;
        }

        return value % MOD;
    }

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();
        long maxwt = 1;

        for (int i = 0; i < m; i++)
            maxwt = (maxwt * radix) % MOD;

        long hashNeedle = hashValue(needle, m), hashHay;

        for (int start = 0; start <= n - m; start++)
        {
            if (start == 0)
            {
                hashHay = hashValue(haystack, m);
            }

            else
            {
                hashHay = ((hashHay * radix) % MOD - ((haystack[start - 1] - 'a') * maxwt) % MOD
                            + haystack[start + m - 1] - 'a' + MOD) % MOD;
            }

            if (hashHay == hashNeedle)
            {
                bool flag = true;

                for (int i = 0; i < m; i++)
                {
                    if (needle[i] != haystack[start + i])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    return start;
            }
        } 

        return -1;
    }
};


// Solved using Rabin Karp Algorithm (Double Hash)
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:
    
    int MOD = 1000000007;
    int MOD2 = 998244353;
    int radix = 26;
    int radix2 = 27;

    pair<long, long> hashValue (string &s, int m)
    {
        long factor = 1, factor2 = 1;
        int value = 0, value2 = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            value += ((s[i] - 'a') * factor) % MOD;
            factor = (factor * radix) % MOD;
            
            value2 += ((s[i] - 'a') * factor2) % MOD2;
            factor2 = (factor2 * radix2) % MOD2;
        }

        return make_pair(value % MOD, value2 % MOD2);
    }

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();
        long maxwt = 1, maxwt2 = 1;

        for (int i = 0; i < m; i++)
        {
            maxwt = (maxwt * radix) % MOD;
            
            maxwt2 = (maxwt2 * radix2) % MOD2;
        }

        pair<long, long> hashNeedle = hashValue(needle, m), hashHay;

        for (int start = 0; start <= n - m; start++)
        {
            if (start == 0)
            {
                hashHay = hashValue(haystack, m);
            }

            else
            {
                hashHay.first = ((hashHay.first * radix) % MOD - ((haystack[start - 1] - 'a') * maxwt) % MOD 
                                + haystack[start + m - 1] - 'a' + MOD) % MOD;
                
                hashHay.second = ((hashHay.second * radix2) % MOD2 - ((haystack[start - 1] - 'a') * maxwt2) % MOD2 
                                + haystack[start + m - 1] - 'a' + MOD2) % MOD2;
            }

            if (hashHay.first == hashNeedle.first && hashHay.second == hashNeedle.second)
            {
                return start;
            }
        } 

        return -1;
    }
};

// Solved using Knuth–Morris–Pratt (KMP) Algorithm
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();
        
        // Longest Proper Prefix that is also a Suffix,  π-table, or Prefix Table
        vector<int> lps (m, 0);
        int prev = 0;
        
        for (int i = 1; i < m;)
        {
            if (needle[i] == needle[prev])
            {
                prev++;
                lps[i] = prev;
                i++;
            }

            else
            {
                if (prev == 0)
                {
                    lps[i] = prev;
                    i++;
                }

                else
                {
                    prev = lps[prev - 1];
                }
            }
        }

        for (int it1 = 0, it2 = 0; it1 < n; )
        {
            if (haystack[it1] == needle[it2])
            {
                it1++;
                it2++;

                if (it2 == m)
                    return it1 - it2;
            }

            else
            {
                if (it2 == 0)
                    it1++;

                else
                    it2 = lps[it2 - 1];
            }
        }

        return -1;
    }
};