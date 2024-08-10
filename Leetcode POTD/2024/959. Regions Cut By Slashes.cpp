// Problem Link :- https://leetcode.com/problems/regions-cut-by-slashes/

// Solved by expanding the grid by 3 times
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();
        vector<vector<int>> expandedGrid(n * 3, vector<int>(n * 3));

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                int baseRow = i * 3, baseCol = j * 3;

                if (grid[i][j] == '\\') 
                {
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } 
                
                else if (grid[i][j] == '/') 
                {
                    expandedGrid[baseRow][baseCol + 2] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol] = 1;
                }
            }
        }

        int regionCount = 0;

        for (int i = 0; i < n * 3; i++) 
        {
            for (int j = 0; j < n * 3; j++) 
            {
                if (expandedGrid[i][j] == 0) 
                {
                    floodFill(expandedGrid, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }

private:

    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void floodFill(vector<vector<int>>& expandedGrid, int row, int col) {
        
        if (!isValidCell(expandedGrid, row, col))
            return;

        expandedGrid[row][col] = 1;

        for (const vector<int>& dir : DIRECTIONS) 
        {
            floodFill(expandedGrid, row + dir[0], col + dir[1]);
        }
    }

    bool isValidCell(const vector<vector<int>>& expandedGrid, int row, int col) 
    {
        int n = expandedGrid.size();
        return row >= 0 && col >= 0 && row < n && col < n && expandedGrid[row][col] == 0;
    }
};



// Solved by Union Find
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size(), totalTriangles = n * n * 4;
        vector<int> parentArray(totalTriangles, -1);

        int regionCount = totalTriangles;

        for (int row = 0; row < n; row++) 
        {
            for (int col = 0; col < n; col++) 
            {
                if (row > 0) 
                {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(n, row - 1, col, 2),
                        getTriangleIndex(n, row, col, 0));
                }

                if (col > 0) 
                {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(n, row, col - 1, 1),
                        getTriangleIndex(n, row, col, 3));
                }

                if (grid[row][col] != '/') 
                {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(n, row, col, 0),
                        getTriangleIndex(n, row, col, 1));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(n, row, col, 2),
                        getTriangleIndex(n, row, col, 3));
                }

                if (grid[row][col] != '\\') 
                {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(n, row, col, 0),
                        getTriangleIndex(n, row, col, 3));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(n, row, col, 2),
                        getTriangleIndex(n, row, col, 1));
                }
            }
        }

        return regionCount;
    }

private:

    int getTriangleIndex(int n, int row, int col, int triangleNum) {
        return (n * row + col) * 4 + triangleNum;
    }

    int unionTriangles(vector<int>& parentArray, int x, int y) {
        
        int parentX = findParent(parentArray, x);
        int parentY = findParent(parentArray, y);

        if (parentX != parentY) 
        {
            parentArray[parentX] = parentY;
            return 1;
        }

        return 0;
    }

    int findParent(vector<int>& parentArray, int x) {

        if (parentArray[x] == -1) 
            return x;

        return parentArray[x] = findParent(parentArray, parentArray[x]);
    }
};



class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size(), pointsPerSide = n + 1;
        int totalPoints = pointsPerSide * pointsPerSide;

        vector<int> parentArray(totalPoints, -1);

        for (int i = 0; i < pointsPerSide; i++) 
        {
            for (int j = 0; j < pointsPerSide; j++) 
            {
                if (i == 0 || j == 0 || i == pointsPerSide - 1 || j == pointsPerSide - 1) 
                {
                    int point = i * pointsPerSide + j;
                    parentArray[point] = 0;
                }
            }
        }

        parentArray[0] = -1;
        int regionCount = 1;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == '/') 
                {
                    int topRight = i * pointsPerSide + (j + 1);
                    int bottomLeft = (i + 1) * pointsPerSide + j;
                    regionCount += union_sets(parentArray, topRight, bottomLeft);
                } 
                
                else if (grid[i][j] == '\\') 
                {
                    int topLeft = i * pointsPerSide + j;
                    int bottomRight = (i + 1) * pointsPerSide + (j + 1);
                    regionCount += union_sets(parentArray, topLeft, bottomRight);
                }
            }
        }

        return regionCount;
    }

private:

    int find(vector<int>& parentArray, int node) {
        
        if (parentArray[node] == -1) 
            return node;

        return parentArray[node] = find(parentArray, parentArray[node]);
    }


    int union_sets(vector<int>& parentArray, int node1, int node2) {

        int parent1 = find(parentArray, node1);
        int parent2 = find(parentArray, node2);

        if (parent1 == parent2)
            return 1;

        parentArray[parent2] = parent1;
        return 0;
    }
};