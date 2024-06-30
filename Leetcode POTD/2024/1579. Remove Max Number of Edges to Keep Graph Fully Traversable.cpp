// Problem Link :- https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

// Solved by Union Find
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class UnionFind {
    
    vector<int> representative, componentSize;
    int components;
    
public:

    UnionFind(int n) {
        
        components = n;
        
        for (int i = 0; i <= n; i++) 
        {
            representative.push_back(i);
            componentSize.push_back(1);
        }
    }
    
    int findRepresentative(int x) {
        
        if (representative[x] == x)
            return x;
        
        return representative[x] = findRepresentative(representative[x]);
    }
    
    int performUnion(int x, int y) {       
        
        x = findRepresentative(x); 
        y = findRepresentative(y);
        
        if (x == y)
            return 0;
        
        if (componentSize[x] > componentSize[y]) 
        {
            componentSize[x] += componentSize[y];
            representative[y] = x;
        } 
        
        else 
        {
            componentSize[y] += componentSize[x];
            representative[x] = y;
        }
        
        components--;
        return 1;
    }
    
    bool isConnected() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        UnionFind Alice(n), Bob(n);

        int edgesRequired = 0;

        for (vector<int>& edge : edges) 
        {
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        for (vector<int>& edge : edges) 
        {
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } 
            
            else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};