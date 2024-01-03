// Problem Link :- https://leetcode.com/problems/last-day-where-you-can-still-cross/

// Solved by Binary Search + DFS
// Time Complexity :- O(row * col * log (row * col))
// Space Complexity :- O(row * col)

class Solution {
public:

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    bool isValid (int x, int y, int row, int col)
    {
        return (x >= 1 && y >= 1 && x <= row && y <= col);
    }

    bool DFS (int x, int y, int &row, int &col, vector<vector<int>> &grid)
    {
        if (x == row)
            return true;

        grid[x][y] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];

            if (isValid(newx, newy, row, col) && grid[newx][newy] == 0)
                if (DFS (newx, newy, row, col, grid))
                    return true;
        }

        return false;
    }

    bool check (int days, int &row, int &col, vector<vector<int>>& cells)
    {
        vector<vector<int>> grid (row + 1, vector<int> (col + 1, 0));

        for (int i = 0; i < days; i++)
        {
            int x = cells[i][0], y = cells[i][1];
            grid[x][y] = 1;
        }

        for (int i = 1; i <= col; i++)
        {
            if (grid[1][i] == 0 && DFS (1, i, row, col, grid))
                return true;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int low = 1, high = row * col, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, row, col, cells))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return high;
    }
};



// Solved by DSU on land cells
// Time Complexity :- O(row * col)
// Space Complexity :- O(row * col)

class DSU {
private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }   
};

class Solution {
public:

    bool isValid (int x, int y, int row, int col)
    {
        return (x >= 1 && y >= 1 && x <= row && y <= col);
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, top = 0, bottom = row * col + 1;
        DSU dsu (row * col + 1);
        vector<vector<int>> grid (row + 1, vector<int> (col + 1, 0));

        for (int i = row * col - 1; i >= 0; i--)
        {
            int x = cells[i][0], y = cells[i][1];
            grid[x][y] = 1;
            int index = (x - 1) * col + y;

            for (int dir = 0; dir < 4; dir++)
            {
                int newx = x + dx[dir], newy = y + dy[dir];
                int newindex = (newx - 1) * col + newy;

                if (isValid(newx, newy, row, col) && grid[newx][newy])
                    dsu.UnionSize(index, newindex);
            }

            if (x == 1)
                dsu.UnionSize(top, index);

            if (x == row)
                dsu.UnionSize(bottom, index);

            if (dsu.findPar(top) == dsu.findPar(bottom))
                return i;
        }

        return 0;
    }
};



// Solved by DSU on water cells
// Time Complexity :- O(row * col)
// Space Complexity :- O(row * col)

class DSU {
private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }   
};

class Solution {
public:

    bool isValid (int x, int y, int row, int col)
    {
        return (x >= 1 && y >= 1 && x <= row && y <= col);
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, -1, 1, -1, 1}, left = 0, right = row * col + 1;
        DSU dsu (row * col + 1);
        vector<vector<int>> grid (row + 1, vector<int> (col + 1, 0));

        for (int i = 0; i < row * col; i++)
        {
            int x = cells[i][0], y = cells[i][1];
            grid[x][y] = 1;
            int index = (x - 1) * col + y;

            for (int dir = 0; dir < 8; dir++)
            {
                int newx = x + dx[dir], newy = y + dy[dir];
                int newindex = (newx - 1) * col + newy;

                if (isValid(newx, newy, row, col) && grid[newx][newy])
                    dsu.UnionSize(index, newindex);
            }

            if (y == 1)
                dsu.UnionSize(left, index);

            if (y == col)
                dsu.UnionSize(right, index);

            if (dsu.findPar(left) == dsu.findPar(right))
                return i;
        }

        return 0;
    }
};