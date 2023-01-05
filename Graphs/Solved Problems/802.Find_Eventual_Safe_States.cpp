//Problem Link :- https://leetcode.com/problems/find-eventual-safe-states/


//Solved by DFS

class Solution {
public:
    
    bool checkCycle (int node, vector <int> &vis, vector <int> &dfsVis, vector <int> &flag, vector <int> adj[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        flag[node] = 0;
        
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle (it, vis, dfsVis, flag, adj) == true)
                {
                    flag[node] = 0;
                    return true;
                }
            }
            
            else if (vis[it] == 1 && dfsVis[it] == 1)
            {
                flag[node] = 0;
                return true;
            }
        }
        
        flag[node] = 1;
        dfsVis[node] = 0;
        
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector <int> adj[n], ans, vis (n, 0), dfsVis (n, 0), flag (n, 0);
        
        for (int i = 0; i < n; i++)
        {
            for  (auto it : graph[i])
                adj[i].emplace_back(it);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                checkCycle(i, vis, dfsVis, flag, adj);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 1)
                ans.emplace_back(i);
        }
        
        return ans;
    }
};



//Solved by BFS

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector <int> adj[n], adjRev[n], indegree(n, 0), ans;

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
                adj[i].emplace_back(it);
        }

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                adjRev[it].emplace_back(i);
                indegree[i]++;
            }
        }

        queue <int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.emplace_back(node);

            for (auto it : adjRev[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }

        sort (ans.begin(), ans.end());

        return ans;
    }
};