// Problem Link :- https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

// Solved by DFS (Reversed Graph)
// Time Complexity :- O(n * (n + m))
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {

        vector<vector<int>> adjacencyList(n);

        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[to].push_back(from);
        }

        vector<vector<int>> ancestorsList;

        for (int i = 0; i < n; i++)
        {

            vector<int> ancestors;
            unordered_set<int> visited;
            findChildren(i, adjacencyList, visited);

            for (int node = 0; node < n; node++)
            {
                if (node == i)
                    continue;
                if (visited.find(node) != visited.end())
                    ancestors.push_back(node);
            }
            ancestorsList.push_back(ancestors);
        }

        return ancestorsList;
    }

private:
    void findChildren(int currentNode, vector<vector<int>> &adjacencyList,
                      unordered_set<int> &visitedNodes) {

        visitedNodes.insert(currentNode);

        for (int neighbour : adjacencyList[currentNode])
        {
            if (visitedNodes.find(neighbour) == visitedNodes.end())
            {
                findChildren(neighbour, adjacencyList, visitedNodes);
            }
        }
    }
};



// Solved by DFS (Optimized)
// Time Complexity :- O(n * (n + m))
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {

        vector<vector<int>> adjacencyList(n), ancestors(n);

        for (vector<int> edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
        }

        for (int i = 0; i < n; i++)
        {
            findAncestorsDFS(i, adjacencyList, i, ancestors);
        }

        return ancestors;
    }

private:
    void findAncestorsDFS(int ancestor, vector<vector<int>> &adjacencyList,
                          int currentNode, vector<vector<int>> &ancestors) {
        for (int childNode : adjacencyList[currentNode])
        {
            if (ancestors[childNode].empty() ||
                ancestors[childNode].back() != ancestor)
            {
                ancestors[childNode].push_back(ancestor);
                findAncestorsDFS(ancestor, adjacencyList, childNode, ancestors);
            }
        }
    }
};



// Solved by BFS (Topological Sort)
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjacencyList(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        queue<int> nodesWithZeroIndegree;
        
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.push(i);
            }
        }

        vector<int> topologicalOrder;
        
        while (!nodesWithZeroIndegree.empty()) {
            
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);
            
            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        vector<vector<int>> ancestorsList(n);
        vector<set<int>> ancestorsSetList(n);

        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {

                ancestorsSetList[neighbor].insert(node);
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        for (int i = 0; i < ancestorsList.size(); i++) {
            ancestorsList[i].assign(ancestorsSetList[i].begin(),
                                    ancestorsSetList[i].end());
            sort(ancestorsList[i].begin(), ancestorsList[i].end());
        }

        return ancestorsList;
    }
};