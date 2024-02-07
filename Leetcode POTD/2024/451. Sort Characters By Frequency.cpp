// Problem Link :- https://leetcode.com/problems/sort-characters-by-frequency/

// Solved using unordered_map and sorting
// Time Complexity :- O(n + 52 * log(52))
// Space Complexity :- O(n)

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freq;

        for (auto &c : s)
            freq[c]++;

        vector<pair<int, char>> freqPairs;

        for (auto &it : freq)
            freqPairs.emplace_back(it.second, it.first);

        sort(freqPairs.begin(), freqPairs.end(), greater<pair<int, char>>());

        string sortedS = "";

        for (auto &it : freqPairs)
        {
            sortedS.append(it.first, it.second);
        }

        return sortedS;
    }
};



// Solved using unordered_map and sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freq;

        for (auto &c : s)
            freq[c]++;

        sort(s.begin(), s.end(), [&](char a, char b){

            if (freq[a] == freq[b])
                return a > b;

            return freq[a] > freq[b];
        });

        return s;
    }
};



// Solved using Bucket Sort
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string frequencySort(string s) {

        int n = s.length();        
        unordered_map<char, int> freq;

        for (auto &c : s)
            freq[c]++;

        vector<string> bucket(n + 1, "");

        for (auto &it : freq)
        {
            bucket[it.second].append(it.second, it.first);
        }

        string sortedS = "";

        for (int i = n; i >= 1; i--)
        {
            if (!bucket[i].empty())
                sortedS.append(bucket[i]);
        }

        return sortedS;
    }
};