//Problem Link :- https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    bool DFScycle(int node, vector <int> &vis, vector <int> &dfsVis, vector <int> adj[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for (auto it : adj[node])
        {
            if(!vis[it])
            {
                if(DFScycle(it, vis, dfsVis, adj) == true)
                    return true;
            }
            
            else if (dfsVis[it] == 1)
                return true;
        }
        
        dfsVis[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses], vis(numCourses, 0), dfsVis(numCourses, 0);
        
        for (auto it : prerequisites)
            adj[it[1]].emplace_back(it[0]);
        
        for (int i = 0; i<numCourses; i++)
        {
            if(!vis[i])
                if(DFScycle(i, vis, dfsVis, adj))
                    return false;
        }
        
        return true;
    }
};