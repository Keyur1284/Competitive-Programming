// Problem Link :- https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set <char> vowels;
        vowels.emplace('a');
        vowels.emplace('e');
        vowels.emplace('i');
        vowels.emplace('o');
        vowels.emplace('u');

        int temp = 0, maxi = 0;
        int n = s.size();

        for (int i = 0; i < min(k, n); i++)
        {
            if(vowels.find(s[i]) != vowels.end())
                temp++;
        }

        maxi = max(maxi, temp);

        for (int start = 1; start <= n - k; start++)
        {
            if (vowels.find(s[start - 1]) != vowels.end())
                temp--;

            if (vowels.find(s[start + k - 1]) != vowels.end())
                temp++;

            maxi = max(maxi, temp);
        }

        return maxi;
    }
};


class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set <char> vowels {'a', 'e', 'i', 'o', 'u'};
        
        int temp = 0, maxi = 0;
        int n = s.size();

        for (int i = 0; i < k; i++)
        {
            temp += vowels.count(s[i]);
        }

        maxi = max(maxi, temp);

        for (int start = k; start < n; start++)
        {
            temp += vowels.count(s[start]) - vowels.count(s[start - k]);
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};


class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set <char> vowels {'a', 'e', 'i', 'o', 'u'};
        
        int temp = 0, maxi = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            temp += vowels.count(s[i]);

            if (i >= k)
                temp -= vowels.count(s[i - k]);

            maxi = max(maxi, temp);
        }

        return maxi;
    }
};