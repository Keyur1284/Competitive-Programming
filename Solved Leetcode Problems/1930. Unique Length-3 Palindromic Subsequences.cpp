// Problem Link :- https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

// Solved by using unordered_set
// Time Complexity :- O(26 * n)
// Space Complexity :- O(26)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length(), count = 0;
        unordered_set<char> letters(s.begin(), s.end());

        for (auto &it : letters)
        {
            int first = -1, last = -1;

            for (int i = 0; i < n; i++)
            {
                if (it == s[i])
                {
                    if (first == -1)
                        first = i;

                    last = i;
                }
            }

            unordered_set<char> between;

            for (int i = first + 1; i <= last - 1; i++)
            {
                between.insert(s[i]);
            }

            count += between.size();
        }

        return count;
    }
};



// Solved by precomputing the first and last occurence of each character
// Time Complexity :- O(26 * n)
// Space Complexity :- O(26)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length(), count = 0;
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) 
        {
            int curr = s[i] - 'a';

            if (first[curr] == - 1)
                first[curr] = i;
            
            last[curr] = i;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (first[i] == -1)
                continue;
            
            unordered_set<char> between;

            for (int j = first[i] + 1; j <= last[i] - 1; j++) 
            {
                between.insert(s[j]);
            }
            
            count += between.size();
        }
        
        return count;
    }
};



// Solved by Binary Search
// Time Complexity :- O(n + 26 * 26 * log(n))
// Space Complexity :- O(26 * n)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length(), count = 0;
        unordered_map<char, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[s[i]].emplace_back(i);

        for (auto &ch : pos)
        {
            if (ch.second.size() < 2)
                continue;

            int start = ch.second.front(), end = ch.second.back();

            for (auto &it : pos)
            {
                auto index = upper_bound(it.second.begin(), it.second.end(), start);
                
                if (index != it.second.end() && *index < end) 
                    count++;
            }
        }

        return count;
    }
};



class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.length(), count = 0;
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].emplace_back(i);

        for (int i = 0; i < 26; i++)
        {
            if (pos[i].size() < 2)
                continue;

            int start = pos[i].front(), end = pos[i].back();

            for (int j = 0; j < 26; j++)
            {
                auto index = upper_bound(pos[j].begin(), pos[j].end(), start);
                
                if (index != pos[j].end() && *index < end) 
                    count++;
            }
        }

        return count;
    }
};