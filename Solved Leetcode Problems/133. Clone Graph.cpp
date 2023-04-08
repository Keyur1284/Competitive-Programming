// Problem Link :- https://leetcode.com/problems/clone-graph/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map <Node*, Node*> copy;

    Node* DFS (Node *node)
    {
        int val = node->val;
        Node* root = new Node (val);
        copy[node] = root;

        for (auto &it : node->neighbors)
        {
            if (copy.find(it) == copy.end())
                root->neighbors.emplace_back(DFS(it));

            else
                root->neighbors.emplace_back(copy[it]);
        }

        return root;
    }
    
    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return NULL;
        
        return DFS(node);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map <Node*, Node*> copy;
    
    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return NULL;
        
        if (copy.find(node) == copy.end())
        {
            int val = node->val;
            copy[node] = new Node(val);

            for (auto &it : node->neighbors)
                copy[node]->neighbors.emplace_back(cloneGraph(it));
        }

        return copy[node];
    }
};


// Solved by BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map <Node*, Node*> copy;

    void BFS (Node *node)
    {
        int val = node->val;

        Node* root = new Node (val);

        queue<Node*> q;
        q.emplace(node);
        copy[node] = root;

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            for (auto &it : curr->neighbors)
            {
                if (copy.find(it) == copy.end())
                {
                    Node* temp = new Node(it->val);
                    copy[it] = temp;
                    q.emplace(it);
                }

                copy[curr]->neighbors.emplace_back(copy[it]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return NULL;
        
        BFS(node);
        
        return copy[node];
    }
};