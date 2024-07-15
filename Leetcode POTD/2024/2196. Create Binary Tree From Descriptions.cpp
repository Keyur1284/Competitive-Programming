// Problem Link :- https://leetcode.com/problems/create-binary-tree-from-descriptions/

// Solved using unordered_map and unordered_set (BFS)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_set<int> children, nodeVals;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for (auto &desc : descriptions)
        {
            nodeVals.emplace(desc[0]);
            nodeVals.emplace(desc[1]);
            children.emplace(desc[1]);
            parentToChildren[desc[0]].emplace_back(desc[1], desc[2]);
        }

        int rootVal;

        for (auto &it : nodeVals)
        {
            if (parentToChildren.count(it) && !children.count(it))
            {
                rootVal = it;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);
        queue<TreeNode*> BFS;
        BFS.emplace(root);

        while(!BFS.empty())
        {
            auto node = BFS.front();
            BFS.pop();

            for (auto &it : parentToChildren[node->val])
            {
                TreeNode* childNode = new TreeNode(it.first);
                (it.second) ? node->left = childNode : node->right = childNode;
                BFS.emplace(childNode);
            }
        }

        return root;
    }
};



// Solved using unordered_map and unordered_set (DFS)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_set<int> children, nodeVals;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for (auto &desc : descriptions)
        {
            nodeVals.emplace(desc[0]);
            nodeVals.emplace(desc[1]);
            children.emplace(desc[1]);
            parentToChildren[desc[0]].emplace_back(desc[1], desc[2]);
        }

        int rootVal;

        for (auto &it : nodeVals)
        {
            if (parentToChildren.count(it) && !children.count(it))
            {
                rootVal = it;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);
        
        function<void(TreeNode*)> buildTree = [&](TreeNode* node)
        {
            for (auto &it : parentToChildren[node->val])
            {
                TreeNode* childNode = new TreeNode(it.first);
                (it.second) ? node->left = childNode : node->right = childNode;
                buildTree(childNode);
            }
        };

        buildTree(root);
        
        return root;
    }
};




// Solved by building tree directly from nodeMap
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_set<int> children;
        unordered_map<int, TreeNode*> nodeMap;

        for (auto &desc : descriptions) 
        {
            if (!nodeMap.count(desc[0]))
                nodeMap[desc[0]] = new TreeNode(desc[0]);
            
            if (!nodeMap.count(desc[1]))
                nodeMap[desc[1]] = new TreeNode(desc[1]);

            (desc[2]) ? nodeMap[desc[0]]->left = nodeMap[desc[1]] : nodeMap[desc[0]]->right = nodeMap[desc[1]];

            children.emplace(desc[1]);
        }


        for (auto &[nodeVal, node] : nodeMap) 
        {
            if (!children.count(nodeVal))
                return node;
        }

        return NULL;
    }
};