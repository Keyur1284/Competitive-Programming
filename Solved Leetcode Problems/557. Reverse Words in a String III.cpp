// Problem Link :- https://leetcode.com/problems/reverse-words-in-a-string-iii/

// Solved using stringstream
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string ans = "", word;

        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }

        ans.pop_back();

        return ans;
    }
};



// Solved using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        int i = 0, j = 0;

        while (j < n)
        {
            while (j < n && s[j] != ' ')
                j++;

            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
            j = i;
        }

        return s;
    }
};



