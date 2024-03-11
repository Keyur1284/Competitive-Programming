// Problem Link :- https://leetcode.com/problems/custom-sort-string/

// Solved by storing order chars and sorting
// Time Complexity :- O(mlogm)      n = order.size() 
// Space Complexity :- O(n + logm)  m = s.size()

class Solution {
public:
    string customSortString(string order, string s) {
        
        int n = order.size();
        vector<int> pos(26, n);

        for (int i = 0; i < n; i++)
        {
            pos[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [&](char a, char b){

            return pos[a - 'a'] < pos[b - 'a'];
        });

        return s;
    }
};



// Solved by storing frequency of s chars
// Time Complexity :- O(n)      n = order.size()
// Space Complexity :- O(26)     m = s.size()

class Solution {
public:
    string customSortString(string order, string s) {
        
        vector<int> freq(26, 0);
        
        for (auto &c :s)
            freq[c - 'a']++;

        string ans = "";

        for (auto &c : order)
        {
            while (freq[c - 'a']--)
            {
                ans += c;
            }

            freq[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            while (freq[i]--)
            {
                ans += (char)(i + 'a');
            }
        }

        return ans;
    }
};