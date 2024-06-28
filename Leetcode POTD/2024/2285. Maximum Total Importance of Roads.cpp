// Problem Link :- https://leetcode.com/problems/maximum-total-importance-of-roads/

// Solved by Sorting Degree of Nodes
// Time Complexity :- O(n^2 + nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);

        for (auto &road : roads)
        {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        sort(degree.begin(), degree.end());
        long long maxImportance = 0, value = 1;

        for (auto &deg : degree)
        {
            maxImportance += value * deg;
            value++;
        }

        return maxImportance;
    }
};