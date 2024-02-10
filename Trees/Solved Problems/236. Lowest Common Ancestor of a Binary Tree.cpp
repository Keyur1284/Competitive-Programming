// Problem Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Solved by finding path to each node
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool findPath (TreeNode* root, TreeNode* node, vector<int> &path)
    {
        if (root == NULL)
            return false;

        path.emplace_back(root->val);

        if (path.back() == node->val)
            return true;

        bool left = findPath (root->left, node, path);
        bool right = findPath (root->right, node, path);

        if (left || right)
            return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<int> path1, path2;

        findPath (root, p, path1);
        findPath (root, q, path2);

        int size = min(path1.size(), path2.size()), i = 0;

        for (i = 0; i < size; i++)
        {
            if (path1[i] == path2[i])
                continue;

            break;
        }

        return new TreeNode(path1[i - 1]);
    }
};



class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        return root;
    }
};



// Solved using Binary Lifting
// Time Complexity :- O(nlogn) for precomputation and O(logn) for each query
// Space Complexity :- O(nlogn)

const int N = 1e5;
const int LOG = 1 + ceil(1.0 * log2(N));
vector<TreeNode*> logVec(LOG, NULL);

class Solution {
public:

    unordered_map<TreeNode*, vector<TreeNode*>> dp;
    unordered_map<TreeNode*, int> depth;

    void findParents(TreeNode* node, TreeNode* parent, int currDepth)
    {
        if (node == NULL)
            return;
        
        dp[node] = logVec;
        dp[node][0] = parent;

        depth[node] = currDepth;

        for (int level = 1; level < LOG; level++)
        {
            TreeNode* levelPar = dp[node][level - 1];

            if (levelPar)
                dp[node][level] = dp[levelPar][level - 1];
        }

        findParents(node->left, node, currDepth + 1);
        findParents(node->right, node, currDepth + 1);
    }

    TreeNode* findLCA(TreeNode* u, TreeNode* v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int level = LOG - 1; level >= 0; level--)
        {
            if (diff & (1 << level))
                u = dp[u][level];
        }

        if (u == v)
            return u;

        for (int level = LOG - 1; level >= 0; level--)
        {
            if (dp[u][level] != dp[v][level])
            {
                u = dp[u][level];
                v = dp[v][level];
            }
        }

        return dp[u][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        findParents(root, NULL, 0);
        return findLCA(p, q);
    }
};



const int N = 1e5;
const int LOG = 1 + ceil(1.0 * log2(N));
vector<int> logVec(LOG, -1);

class Solution {
public:

    unordered_map<int, vector<int>> dp;
    unordered_map<int, int> depth;

    void findParents(TreeNode* node, int parent, int currDepth)
    {
        if (node == NULL)
            return;
        
        int nodeVal = node->val;

        dp[nodeVal] = logVec;
        dp[nodeVal][0] = parent;

        depth[nodeVal] = currDepth;

        for (int level = 1; level < LOG; level++)
        {
            int levelPar = dp[nodeVal][level - 1];

            if (levelPar != -1)
                dp[nodeVal][level] = dp[levelPar][level - 1];
        }

        findParents(node->left, nodeVal, currDepth + 1);
        findParents(node->right, nodeVal, currDepth + 1);
    }

    int findLCA(TreeNode* u, TreeNode* v)
    {
        int x = u->val, y = v->val;

        if (depth[x] < depth[y])
            swap(x, y);

        int diff = depth[x] - depth[y];

        for (int level = LOG - 1; level >= 0; level--)
        {
            if (diff & (1 << level))
                x = dp[x][level];
        }

        if (x == y)
            return x;

        for (int level = LOG - 1; level >= 0; level--)
        {
            if (dp[x][level] != dp[y][level])
            {
                x = dp[x][level];
                y = dp[y][level];
            }
        }

        return dp[x][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        findParents(root, -1, 0);

        int LCA = findLCA(p, q);

        return new TreeNode(LCA);
    }
};