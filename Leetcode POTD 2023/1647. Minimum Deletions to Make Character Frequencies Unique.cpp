// Problem Link :- https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

// Solved by using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char, int> freq;

        for (auto &it : s)
        {
            freq[it]++;
        }

        vector<int> vec;

        for (auto &it : freq)
        {
            vec.emplace_back(it.second);
        }

        sort (vec.begin(), vec.end());

        int del = 0;

        for (int i = vec.size() - 2; i >= 0; i--)
        {
            while (vec[i] && vec[i] >= vec[i + 1])
            {
                del++;
                vec[i]--;
            }
        }
 
        return del;
    }
};



class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char, int> freq;

        for (auto &it : s)
        {
            freq[it]++;
        }

        vector<int> vec;

        for (auto &it : freq)
        {
            vec.emplace_back(it.second);
        }

        sort (vec.begin(), vec.end());

        int del = 0;

        for (int i = vec.size() - 2; i >= 0; i--)
        {
            if (vec[i] >= vec[i + 1])
            {
                int initial = vec[i];
                vec[i] = max(0, vec[i + 1] - 1);
                del += initial - vec[i];
            }
        }
 
        return del;
    }
};