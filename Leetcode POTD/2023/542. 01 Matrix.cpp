// Problem Link :- https://leetcode.com/problems/01-matrix/

// Solved by BFS
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        vector<vector<int>> ans (m, vector<int> (n, 1e9));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        
        while (!q.empty())
        {
            auto it = q.front();
            int x = it.first, y = it.second;
            q.pop();
                        
            for (int it = 0; it < 4; it++)
            {
                int newx = x + dx[it];
                int newy = y + dy[it];
                
                if (isValid(newx, newy, m, n) && ans[newx][newy] > 1 + ans[x][y])
                {
                    ans[newx][newy] = 1 + ans[x][y];
                    q.emplace(newx, newy);
                }
            }
        }
        
        return ans;
    }
};



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