// Problem Link :- https://leetcode.com/problems/destination-city/

// Solved using unordered_set
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> srcCities;

        for (auto &it : paths)
            srcCities.emplace(it[0]);

        for (auto &it : paths)
        {
            if (!srcCities.count(it[1]))
                return it[1];
        }

        return "";
    }
};