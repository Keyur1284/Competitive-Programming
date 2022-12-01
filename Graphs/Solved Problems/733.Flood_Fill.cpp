//Problem Link :- https://leetcode.com/problems/flood-fill/

class Solution {
public:
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void DFS (int i, int j, int color, int m, int n, int initial, vector<vector<int>>& image, vector<vector<int>>& ans)
    {
        ans[i][j] = color;
            
        for (int it = 0; it < 4; it++)
        {    
            int newx = i + dx[it];
            int newy = j + dy[it];

            if (newx >= 0 && newy >= 0 && newx < m && newy < n && image[newx][newy] == initial && ans[newx][newy] != color)
            {
                DFS (newx, newy, color, m, n, initial, image, ans);
            }
        }
            
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        
        int initial = image[sr][sc];
        
        vector<vector <int>> ans = image;
        
        DFS(sr, sc, color, m, n, initial, image, ans);
        
        return ans;
    }
};