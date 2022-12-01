//Problem Link :- https://leetcode.com/problems/01-matrix/

class Solution {
public:
    
    struct Node {
        
        int x, y, dist;
        
        Node (int a, int b, int c)
        {
            x = a;
            y = b;
            dist = c;
        }
    };
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        vector <vector <int>> ans (m, vector <int> (n, 0)), vis (m, vector <int> (n, 0));
        queue <Node> q;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.emplace(Node(i, j, 0));
                }
            }
        }
        
        while (!q.empty())
        {
            int i = q.front().x;
            int j = q.front().y;
            int steps = q.front().dist;
            q.pop();
            
            ans[i][j] = steps;
            
            for (int it = 0; it < 4; it++)
            {
                int newx = i + dx[it];
                int newy = j + dy[it];
                
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && !vis[newx][newy])
                {
                    vis[newx][newy] = 1;
                    q.emplace(Node(newx, newy, steps + 1));
                }
            }
        }
        
        return ans;
    }
};