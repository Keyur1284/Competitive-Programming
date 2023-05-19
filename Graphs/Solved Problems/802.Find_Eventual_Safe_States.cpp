//Problem Link :- https://leetcode.com/problems/find-eventual-safe-states/


//Solved by DFS

class Solution {
public:

    bool checkCycle (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<bool> &flag, vector<vector<int>>& graph)
    {
        vis[node] = true;
        dfsVis[node] = true;
        flag[node] = false;

        for (auto &it : graph[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, vis, dfsVis, flag, graph))
                {
                    flag[node] = false;
                    return true;
                }
            }

            else if (vis[it] && dfsVis[it])
            {
                flag[node] = false;
                return true;
            }
        }

        flag[node] = true;
        dfsVis[node] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> vis (n, false), dfsVis (n, false), flag (n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                checkCycle(i, vis, dfsVis, flag, graph);
            }
        }

        vector<int> safeNodes;

        for (int i = 0; i < n; i++)
        {
            if (flag[i])
                safeNodes.emplace_back(i);
        }

        return safeNodes;
    }
};



//Solved by BFS

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adjRev[n], indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto &it : graph[i])
            {
                adjRev[it].emplace_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

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

            for (auto &it : adjRev[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans; 
    }
};