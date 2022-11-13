//Problem Link :- https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses], indegree(numCourses, 0), topo;
        
        for (auto it : prerequisites)
        {
            adj[it[1]].emplace_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue <int> q;
	    
        for(int i = 0; i<numCourses; i++) 
        {        
            if(indegree[i] == 0) 
                q.emplace(i);  
        }
        
        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            topo.emplace_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }
        
        
        if (count != numCourses)
        {
            vector <int> empty;
            return empty;
        }

        return topo;
    }
};