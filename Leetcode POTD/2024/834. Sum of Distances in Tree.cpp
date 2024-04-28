// Problem Link :- https://leetcode.com/problems/sum-of-distances-in-tree/

// Solved by Brute Force Approach (DFS) (TLE)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    void dfs(int node, int parent, int level, int &sum, vector<int> adj[])
    {
        for (auto &it : adj[node])
        {
            if (it != parent)
            {
                sum += level;
                dfs(it, node, level + 1, sum, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n], res(n);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            dfs(i, -1, 1, sum, adj);
            res[i] = sum;
        }

        return res;
    }
};



class Solution {
public:
    
    int dfs (int node, int parent, int level, vector<int> adj[])
    {
        int sum = 0;
        
        for (auto &it : adj[node])
        {
            if (it != parent)
            {
                sum += level + dfs(it, node, level + 1, adj);
            }
        }
        
        return sum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n], res(n);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        
        for (int i = 0; i < n; i++)
        {
            res[i] = dfs(i, -1, 1, adj);
        }

        return res;
    }
};



// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    void DFS(int node, int parent, vector<int> &answer, vector<int> &childCount, vector<int> adj[])
    {
        for (auto &child : adj[node])
        {
            if (child != parent)
            {
                DFS(child, node, answer, childCount, adj);
                childCount[node] += childCount[child];
                answer[node] += answer[child] + childCount[child];
            }
        }
    }

    void DFS2(int node, int parent, int &n, vector<int> &answer, vector<int> &childCount, vector<int> adj[])
    {
        for (auto &child : adj[node])
        {
            if (child != parent)
            {
                answer[child] = answer[node] - (childCount[child]) + (n - childCount[child]);
                DFS2(child, node, n, answer, childCount, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n], answer(n, 0), childCount(n, 1);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        DFS(0, -1, answer, childCount, adj);
        DFS2(0, -1, n, answer, childCount, adj);

        return answer;
    }
};