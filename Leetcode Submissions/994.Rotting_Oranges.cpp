//Problem Link :- https://leetcode.com/problems/rotting-oranges/

struct Node {
    int x, y, time;
    
    Node (int a, int b, int c)
    {
        x = a;
        y = b; 
        time = c;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue <Node> q;
        int row = grid.size();
        int col = grid[0].size();
        int oranges = 0;
        
        for (int i = 0; i<row; i++)
        {
            for (int j = 0; j<col; j++)
            {
                if (grid[i][j] != 0)
                    oranges++;
                
                if (grid[i][j] == 2)
                    q.emplace(Node(i, j, 0));
            }
        }
        
        int ans = 0, count = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            count++;
            
            ans = max (ans, time);
         
            for (int i = 0; i<4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && grid[newx][newy] == 1)
                {
                    grid[newx][newy] = 2;
                    q.emplace(Node(newx, newy, time + 1));
                }
            }
        }
        
        if (count == oranges)
            return ans;
        
        else
            return -1;
        
    }
};