// Problem Link :- https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

// Solved by Dijkstra's Algorithm
// Time Complexity :- O(N + M * (V + E * logV))      N is the number of nodes, M is the number of calls
// Space Complexity :- O(N + E + V)          V is the number of vertices, E is the number of edges

class Graph {
public:

    vector<vector<pair<int, int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {
        
        adj.resize(n);

        for (auto &edge : edges)
            addEdge(edge);
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minDist(n, INT_MAX);

        pq.emplace(0, node1);
        minDist[node1] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            int dist = curr.first, node = curr.second;
            pq.pop();

            if (node == node2)
                return dist;

            for (auto &it : adj[node])
            {
                if (it.second + dist < minDist[it.first])
                {
                    minDist[it.first] = it.second + dist;
                    pq.emplace(minDist[it.first], it.first);
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */



// Solved by Floyd Warshall Algorithm
// Time Complexity :- O(V^3 + N * V^2 + M)  N is the number of nodes, M is the number of calls
// Space Complexity :- O(V^2)          V is the number of vertices, E is the number of edges

class Graph {
public:
    
    vector<vector<int>> adj;

    Graph (int n, vector<vector<int>>& edges) {
        
        adj = vector<vector<int>> (n, vector<int> (n, 1e9));

        for (auto &it : edges)
            adj[it[0]][it[1]] = it[2];

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
       
        int n = adj.size();
       
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][edge[0]] + adj[edge[1]][j] + edge[2]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        
        return (adj[node1][node2] == 1e9) ? -1 : adj[node1][node2];
    }
};