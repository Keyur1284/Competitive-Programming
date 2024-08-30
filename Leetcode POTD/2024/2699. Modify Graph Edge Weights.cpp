// Problem Link :- https://leetcode.com/problems/modify-graph-edge-weights/

// Solved by Dijkstra Algorithm
// Time Complexity :- O(E * ((V + E) * logV))
// Space Complexity :- O(V + E)

class Solution {
public:
    
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        vector<vector<pair<int, int>>> graph(n);

        for (auto &edge : edges) 
        {
            if (edge[2] != -1) 
            {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        int currentShortestDistance = runDijkstra(n, source, destination, graph);
        
        if (currentShortestDistance < target)
            return vector<vector<int>>();

        bool matchesTarget = (currentShortestDistance == target);

        for (auto& edge : edges) 
        {
            if (edge[2] != -1)
                continue;

            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);

            if (!matchesTarget) 
            {    
                int newDistance = runDijkstra(n, source, destination, graph);
                
                if (newDistance <= target) 
                {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return matchesTarget ? edges : vector<vector<int>>();
    }

private:
    int runDijkstra(int n, int source, int destination, vector<vector<pair<int, int>>>& graph) 
    {
        vector<int> minDistance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) 
        {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > minDistance[u]) 
                continue;

            for (auto &[v, weight] : graph[u]) 
            {
                if (d + weight < minDistance[v]) 
                {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        return minDistance[destination];
    }
};