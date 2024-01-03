// Problem Link :- https://leetcode.com/problems/validate-binary-tree-nodes/

// Solved by DFS 
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;

            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        int root = -1;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (root != -1)
                    return false;

                root = i;
            }
        }

        if (root == -1)
            return false;

        vector<bool> visited(n, false);
        visited[root] = true;

        stack<int> st;
        st.push(root);

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (leftChild[node] != -1)
            {
                if (visited[leftChild[node]])
                    return false;

                visited[leftChild[node]] = true;
                st.push(leftChild[node]);
            }

            if (rightChild[node] != -1)
            {
                if (visited[rightChild[node]])
                    return false;

                visited[rightChild[node]] = true;
                st.push(rightChild[node]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                return false;
        }

        return true;
    }
};



// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;

            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        int root = -1;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (root != -1)
                    return false;

                root = i;
            }
        }

        if (root == -1)
            return false;

        vector<bool> visited(n, false);
        visited[root] = true;

        queue<int> q;
        q.push(root);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (leftChild[node] != -1)
            {
                if (visited[leftChild[node]])
                    return false;

                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }

            if (rightChild[node] != -1)
            {
                if (visited[rightChild[node]])
                    return false;

                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                return false;
        }

        return true;
    }
};



// Solved by Union Find
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class DSU {
private:

    int components;
    vector<int> parents;

public:

    DSU (int n)
    {
        components = n;

        for (int i = 0; i < n; i++)
            parents.emplace_back(i);
    }

    int findPar (int node)
    {
        if (parents[node] == node)
            return node;

        return parents[node] = findPar(parents[node]);
    }

    bool merge (int child, int parent)
    {
        int childParent = findPar(child);
        int parentParent = findPar(parent);

        if (childParent != child || parentParent == child)
            return false;

        components--;
        parents[childParent] = parentParent;
        return true;
    }

    int getComponents ()
    {
        return components;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        DSU dsu(n);

        for (int i = 0; i < n; i++)
        {
            vector<int> child = {leftChild[i], rightChild[i]};

            for (auto &it : child)
            {
                if (it != -1 && !dsu.merge(it, i))
                    return false;
            }
        }

        return (dsu.getComponents() == 1);
    }
};