// Problem Link :- https://leetcode.com/problems/n-ary-tree-postorder-traversal/

// Solved by Recursive Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    vector<int> nodes;

    void DFS(Node* node)
    {
        if (node == NULL)
            return;

        for (auto &child : node->children)
            DFS(child);

        nodes.emplace_back(node->val);
    }

    vector<int> postorder(Node* root) {
        
        DFS(root);
        return nodes;
    }
};