// Problem Link :- https://leetcode.com/problems/path-with-maximum-probability/

// Solved by Dijkstra's Algorithm
// Time Complexity :- O(ElogV)
// Space Complexity :- O(V + E)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        int totalEdges = edges.size();
        vector<pair<int, int>> adj[n];
        
        for (int i = 0; i < totalEdges; i++)
        {
            adj[edges[i][0]].emplace_back(edges[i][1], i);
            adj[edges[i][1]].emplace_back(edges[i][0], i);
        }
        
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start);

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            double prob = it.first;
            int node = it.second;
            
            if (node == end)
                return prob;

            if (maxProb[node] > prob)
                continue;

            for (auto &it : adj[node])
            {
                double newProb = prob * succProb[it.second];
                
                if (maxProb[it.first] < newProb)
                {
                    maxProb[it.first] = newProb;
                    pq.emplace(maxProb[it.first], it.first);
                }
            }
        }

        return maxProb[end];
    }
};



// Solved by Bellman Ford Algorithm
// Time Complexity :- O(V * E)
// Space Complexity :- O(V)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        int totalEdges = edges.size();
        
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        for (int i = 0; i < n - 1; i++)
        {
            bool update = false;

            for (int j = 0; j < totalEdges; j++)
            {
                int u = edges[j][0], v = edges[j][1];
                double pathProb = succProb[j];

                if (maxProb[u] < maxProb[v] * pathProb)
                {
                    maxProb[u] = maxProb[v] * pathProb;
                    update = true;
                }

                if (maxProb[v] < maxProb[u] * pathProb)
                {
                    maxProb[v] = maxProb[u] * pathProb;
                    update = true;
                }
            }

            if (!update)
                break;
        }

        return maxProb[end];
    }
};