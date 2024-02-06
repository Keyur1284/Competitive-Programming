// Problem Link :- https://leetcode.com/problems/group-anagrams/

// Solved using unordered_map
// Time Complexity :- O(n * m * logm)      n = number of strings
// Space Complexity :- O(n)             m = average length of strings

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for (auto &it : strs)
        {
            string s = it;
            sort(s.begin(), s.end());

            mp[s].emplace_back(it);
        }

        vector<vector<string>> ans;

        for (auto &it : mp)
        {
            ans.emplace_back(it.second);
        }

        return ans;
    }
};



// Solved using map
// Time Complexity :- O(n * m * logn)      n = number of strings
// Space Complexity :- O(n)               m = average length of strings

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> mp;

        for (auto &it : strs)
        {
            vector<int> freq(26, 0);

            for (auto &ch : it)
            {
                freq[ch - 'a']++;
            }

            mp[freq].emplace_back(it);
        }

        vector<vector<string>> ans;

        for (auto &it : mp)
        {
            ans.emplace_back(it.second);
        }

        return ans;
    }
};



// Solved using unordered_map and custom hash function
// Time Complexity :- O(n * m)      n = number of strings
// Space Complexity :- O(n)         m = average length of strings

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for (auto &it : strs)
        {
            vector<int> freq(26, 0);

            for (auto &ch : it)
            {
                freq[ch - 'a']++;
            }

            string s = "";

            for (auto &x : freq)
            {
                s += to_string(x) + "$";
            }

            mp[s].emplace_back(it);
        }

        vector<vector<string>> ans;

        for (auto &it : mp)
        {
            ans.emplace_back(it.second);
        }

        return ans;
    }
};