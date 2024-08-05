// Problem Link :- https://leetcode.com/problems/kth-distinct-string-in-an-array/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> freq;

        for (auto &str : arr)
            freq[str]++;

        for (auto &str : arr)
        {
            if (freq[str] == 1)
                k--;

            if (k == 0)
                return str;
        }

        return "";
    }
};