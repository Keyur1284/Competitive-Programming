// Problem Link :- https://www.codingninjas.com/codestudio/problems/left-view-of-binary-tree_625707

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void DFS (BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.emplace_back(root->data);

    DFS (root->left, level + 1, ans);
    DFS (root->right, level + 1, ans);
}

void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        cout << -1 << endl;
        return;
    }

    DFS (root, 0, ans);

    for (auto &it : ans)
        cout << it << " ";

    cout << endl;
}


// Solved by BFS

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        cout << -1 << endl;
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.emplace(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 1; i <= size; i++)
        {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            
            if (i == 1)
                ans.emplace_back(node->data);

            if (node->left)
                q.emplace(node->left);

            if (node->right)
                q.emplace(node->right);
        }
    }

    for (auto &it : ans)
        cout << it << " ";

    cout << endl;
}