// Problem Link :- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Solved by doing preorder traversal
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        return (root == NULL) ? " $" : " " + to_string(root->val) + serialize (root->left) + serialize (root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        return buildTree(ss);
    }

    TreeNode* buildTree (stringstream &ss)
    {
        string st;
        ss >> st;

        if (st == "$")
            return NULL;

        int val = stoi(st);
        TreeNode* node = new TreeNode(val);
        node->left = buildTree(ss);
        node->right = buildTree(ss);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



// Solved by doing levelorder traversal
// Time Complexity :- O(N)
// Space Complexity :- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string levelOrder = "";
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL)
                levelOrder += " $";

            else
            {
                string data = " " + to_string(node->val);
                levelOrder += data;
                q.emplace(node->left);
                q.emplace(node->right);
            }
        }

        return levelOrder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        string st;

        ss >> st;
        
        if (st == "$")
            return NULL;

        TreeNode* root = new TreeNode(stoi(st));
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            ss >> st;

            if (st == "$")
                node->left = NULL;

            else
            {
                TreeNode* leftNode = new TreeNode (stoi(st));
                node->left = leftNode;
                q.emplace(leftNode);
            }

            ss >> st;

            if (st == "$")
                node->right = NULL;

            else
            {
                TreeNode* rightNode = new TreeNode (stoi(st));
                node->right = rightNode;
                q.emplace(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string levelOrder = "";
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL)
                levelOrder += "$,";

            else
            {
                string data = to_string(node->val) + ",";
                levelOrder += data;
                q.emplace(node->left);
                q.emplace(node->right);
            }
        }

        return levelOrder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        string st;

        getline (ss, st, ',');
        
        if (st == "$")
            return NULL;

        TreeNode* root = new TreeNode(stoi(st));
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            getline (ss, st, ',');

            if (st == "$")
                node->left = NULL;

            else
            {
                TreeNode* leftNode = new TreeNode (stoi(st));
                node->left = leftNode;
                q.emplace(leftNode);
            }

            getline (ss, st, ',');

            if (st == "$")
                node->right = NULL;

            else
            {
                TreeNode* rightNode = new TreeNode (stoi(st));
                node->right = rightNode;
                q.emplace(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));