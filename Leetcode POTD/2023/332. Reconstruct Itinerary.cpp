// Problem Link :- https://leetcode.com/problems/reconstruct-itinerary/

// Solved by DFS
// Time Complexity :- O(E * logE)
// Space Complexity :- O(E)

class Solution {
public:

    void DFS (string node, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adj, vector<string> &itenary)
    {
        while(!adj[node].empty())
        {
            string next = adj[node].top();
            adj[node].pop();
            DFS(next, adj, itenary);
        }

        itenary.emplace_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for (auto &it : tickets)
        {
            adj[it[0]].emplace(it[1]);
        }

        vector<string> itenary;
        string start = "JFK";

        DFS (start, adj, itenary);
        reverse(itenary.begin(), itenary.end());

        return itenary;
    }
};