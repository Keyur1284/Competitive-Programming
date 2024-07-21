// Problem Link :- https://leetcode.com/problems/build-a-matrix-with-conditions/

// Solved by Topological Sort
// Time Complexity :- O(max(k * k, n + m))
// Space Complexity :- O(max(k * k, n + m))

class Solution {
public:
    
    vector<int> topoSort(int &k, vector<vector<int>> &edges)
    {
        vector<int> adj[k + 1], indegree(k + 1, 0);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 1; i <= k; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            topo.emplace_back(node);
            q.pop();

            for (auto &it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }

        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {

        int n = rowConditions.size(), m = colConditions.size();
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);

        if (rowOrder.size() != k || colOrder.size() != k)
        {
            vector<vector<int>> empty;
            return empty;
        }

        vector<int> rowIndex(k + 1), colIndex(k + 1);

        for (int i = 0; i < k; i++)
            rowIndex[rowOrder[i]] = i;

        for (int i = 0; i < k; i++)
            colIndex[colOrder[i]] = i;

        vector<vector<int>> grid(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i++)
            grid[rowIndex[i]][colIndex[i]] = i;

        return grid;
    }
};



class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        
        vector<vector<int>> adj(n + 1);
        vector<int> order;

        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        for (int i = 1; i <= n; i++) {
            
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                if (hasCycle) return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order, bool& hasCycle) {
        
        visited[node] = 1;

        for (int neighbor : adj[node]) 
        {
            if (visited[neighbor] == 0) {
                
                dfs(neighbor, adj, visited, order, hasCycle);
                if (hasCycle) return;
            } 
            
            else if (visited[neighbor] == 1) {

                hasCycle = true;
                return;
            }
        }

        visited[node] = 2;
        order.push_back(node);
    }
};



class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:

    vector<int> topoSort(vector<vector<int>>& edges, int n) {

        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1), order;
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for (auto v : adj[f]) {
                if (--deg[v] == 0) q.push(v);
            }
        }

        if (n != 0) return {};
        return order;
    }
};