// Problem Link :- https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// Solved by Graph Conversion + BFS
// Time Complexity :- O(n^2)
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

class Solution{
private:

    void traverseTree(TreeNode *currNode, TreeNode *prevNode) {

        if (currNode == NULL)
            return;

        if (currNode->left == NULL && currNode->right == NULL)
            leafNodes.emplace(currNode);

        if (prevNode)
        {
            graph[prevNode].emplace_back(currNode);
            graph[currNode].emplace_back(prevNode);
        }

        traverseTree(currNode->left, currNode);
        traverseTree(currNode->right, currNode);
    }

public:
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    unordered_set<TreeNode *> leafNodes;

    int countPairs(TreeNode *root, int distance) {

        traverseTree(root, NULL);

        int goodLeafs = 0;

        for (auto &leaf : leafNodes)
        {
            queue<TreeNode*> bfsQueue;
            unordered_set<TreeNode*> seen;
            bfsQueue.emplace(leaf);
            seen.emplace(leaf);

            for (int i = 0; i <= distance; i++)
            {
                int size = bfsQueue.size();

                for (int j = 0; j < size; j++)
                {
                    TreeNode *currNode = bfsQueue.front();
                    bfsQueue.pop();

                    if (leafNodes.count(currNode) && currNode != leaf)
                        goodLeafs++;
                    
                    if (graph.count(currNode))
                    {
                        for (auto &neighbor : graph[currNode])
                        {
                            if (!seen.count(neighbor))
                            {
                                bfsQueue.emplace(neighbor);
                                seen.emplace(neighbor);
                            }
                        }
                    }
                }
            }
        }

        return goodLeafs / 2;
    }
};



// Solved by Post Order Traversal
// Time Complxity :- O(n * d^2)
// Space Complexity :- O(height)

class Solution {
private:
    
    vector<int> postOrder(TreeNode* currentNode, int distance) {
        
        if (currentNode == NULL)
            return vector<int>(12);
        
        if (currentNode->left == NULL && currentNode->right == NULL) 
        {
            vector<int> current(12);
            current[0] = 1;
            return current;
        }

        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right, distance);

        vector<int> current(12);

        for (int i = 0; i < 10; i++) 
        {
            current[i + 1] = left[i] + right[i];
        }

        current[11] += left[11] + right[11];

        for (int d1 = 0; d1 <= distance; d1++) 
        {
            for (int d2 = 0; d2 <= distance; d2++) 
            {
                if (2 + d1 + d2 <= distance) 
                {
                    current[11] += left[d1] * right[d2];
                }
            }
        }

        return current;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};



class Solution {
public:

    int goodLeafs = 0;

    vector<int> DFS(TreeNode* node, int distance)
    {
        if (node == NULL)
            return {};

        if (node->left == NULL && node->right == NULL)
            return {1};

        auto leftLeafs = DFS(node->left, distance);
        auto rightLeafs = DFS(node->right, distance);

        for (auto &leftDist : leftLeafs)
        {
            for (auto &rightDist : rightLeafs)
            {
                if (leftDist + rightDist <= distance)
                    goodLeafs++;
            }
        }

        vector<int> currDist;

        for (auto &leftDist : leftLeafs)
        {
            if (1 + leftDist < distance)
                currDist.emplace_back(1 + leftDist);
        }

        for (auto &rightDist : rightLeafs)
        {
            if (1 + rightDist < distance)
                currDist.emplace_back(1 + rightDist);
        }

        return currDist;
    }

    int countPairs(TreeNode* root, int distance) {
        
        DFS(root, distance);
        return goodLeafs;
    }
};



// Solved using unordered_map

class Solution {
public:

    int goodLeafs = 0;

    unordered_map<int, int> DFS(TreeNode* node, int distance)
    {
        if (node == NULL)
            return {};

        if (node->left == NULL && node->right == NULL)
            return {{1, 1}};

        auto leftLeafs = DFS(node->left, distance);
        auto rightLeafs = DFS(node->right, distance);

        for (auto &[leftDist, leftFreq] : leftLeafs)
        {
            for (auto &[rightDist, rightFreq] : rightLeafs)
            {
                if (leftDist + rightDist <= distance)
                    goodLeafs += leftFreq * rightFreq;
            }
        }

        unordered_map<int, int> currDist;

        for (auto &[leftDist, leftFreq] : leftLeafs)
        {
            if (1 + leftDist < distance)
                currDist[1 + leftDist] += leftFreq;
        }

        for (auto &[rightDist, rightFreq] : rightLeafs)
        {
            if (1 + rightDist < distance)
                currDist[1 + rightDist] += rightFreq;
        }

        return currDist;
    }

    int countPairs(TreeNode* root, int distance) {
        
        DFS(root, distance);
        return goodLeafs;
    }
};