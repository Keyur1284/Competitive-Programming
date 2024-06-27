// Problem Link :- https://leetcode.com/problems/find-center-of-star-graph/

// Solved by counting degree
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size() + 1;
        vector<int> degree(n + 1, 0);

        for (auto &edge : edges) 
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for (int i = 1; i <= n; i++) 
        {
            if (degree[i] == n - 1) 
                return i;
        }

        return -1;
    }
};



// Solved by comparing edges
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        vector<int> firstEdge = edges[0], secondEdge = edges[1];

        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1]) ? firstEdge[0] : firstEdge[1];
    }
};