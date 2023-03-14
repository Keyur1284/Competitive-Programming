// Binary Tree Representation in C++
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Tree Traversal Techniques

// Recursive In-order Traversal    
void inOrder (TreeNode* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Iterative In-order Traversal
void inOrderIterative (TreeNode* root)
{
    if (root == NULL)
        return;

    TreeNode* curr = root;
    stack<TreeNode*> st;
    st.emplace(curr);

    while (!st.empty())
    {
        while (curr->left)
        {
            curr = curr->left;
            st.emplace(curr);
        }

        curr = st.top();
        st.pop();
        curr->left = NULL;

        cout << curr->val << " ";

        if (curr->right)
        {
            curr = curr->right;
            st.emplace(curr);
        }
    }
}

// Recursive Pre-order Traversal
void preOrder (TreeNode* root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Iterative Pre-order Traversal
void preOrderIterative (TreeNode* root)
{
    if (root == NULL)
        return;

    stack<TreeNode*> st;
    st.emplace(root);

    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();

        cout << node->val << " ";

        if (node->right)
            st.emplace(node->right);

        if (node->left)
            st.emplace(node->left);
    }
}

// Recursive Post-order Traversal
void postOrder (TreeNode* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

// Iterative Post-order Traversal (Using 2 Stacks)
void postOrderIterative2 (TreeNode* root)
{
    if (root == NULL)
        return;

    stack<TreeNode*> st1, st2;
    st1.emplace(root);

    while (!st1.empty())
    {
        TreeNode* node = st1.top();
        st1.pop();
        st2.emplace(node);

        if (node->left)
            st1.emplace(node->left);

        if (node->right)
            st1.emplace(node->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->val << " ";
        st2.pop();
    }
}

// Iterative Post-order Traversal (Using 1 Stack)
void postOrderIterative1 (TreeNode* root)
{
    if (root == NULL)
        return;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.emplace(curr);
            curr = curr->left;
        }

        else
        {
            TreeNode* temp = st.top()->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->val << " ";

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->val << " ";
                }
                
            }

            else
                curr = temp;
        }
    }
}

// Level-order Traversal
void levelOrder (TreeNode* root)
{
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.emplace(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left)
            q.emplace(node->left);

        if (node->right)
            q.emplace(node->right);
    }
}

// In-order, Pre-order and Post-order in one Function

vector<int> in, pre, post;

// Recursive Approach

void AllinOne (TreeNode* root)
{
    if (root == NULL)
        return;

    pre.emplace_back(root->val);
    AllinOne(root->left);
    in.emplace_back(root->val);
    AllinOne(root->right);
    post.emplace_back(root->val);
}

// Iterative Approach

void AllinOneIterative (TreeNode* root)
{
    if (root == NULL)
        return;

    in.clear(), pre.clear(), post.clear();

    stack<pair<TreeNode*, int>> st;
    st.emplace(root, 1);

    while (!st.empty())
    {
        TreeNode* node = st.top().first;
        int state = st.top().second;
        st.pop();

        if (state == 1)
        {
            pre.emplace_back(node->val);
            st.emplace(node, state + 1);

            if (node->left)
                st.emplace(node->left, 1);
        }

        else if (state == 2)
        {
            in.emplace_back(node->val);
            st.emplace(node, state + 1);

            if (node->right)
                st.emplace(node->right, 1);
        }

        else
            post.emplace_back(node->val);
    }
}

int main() {
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Binary Tree Representation: " << endl;
    cout << "        1        " << endl;
    cout << "       / \\       " << endl;
    cout << "      2   3      " << endl;
    cout << "     / \\ / \\     " << endl;
    cout << "    4  5 6  7    " << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "In-order Traversal (Iterative): ";
    inOrderIterative(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Pre-order Traversal (Iterative): ";
    preOrderIterative(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Post-order Traversal (Iterative - 2 Stacks): ";
    postOrderIterative2(root);
    cout << endl;

    cout << "Post-order Traversal (Iterative - 1 Stack): ";
    postOrderIterative1(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrder(root);
    cout << endl;

    cout << "In-order, Pre-order and Post-order in one Function: " << endl;
    AllinOne(root);
    
    cout << "In-order: ";
    for (auto &it : in)
        cout << it << " ";
    cout << endl;
    
    cout << "Pre-order: ";
    for (auto &it : pre)
        cout << it << " ";
    cout << endl;

    cout << "Post-order: ";
    for (auto &it : post)
        cout << it << " ";
    cout << endl;

    cout << "In-order, Pre-order and Post-order in one Function (Iterative): " << endl;
    AllinOneIterative(root);

    cout << "In-order: ";
    for (auto &it : in)
        cout << it << " ";
    cout << endl;

    cout << "Pre-order: ";
    for (auto &it : pre)
        cout << it << " ";
    cout << endl;
    
    cout << "Post-order: ";
    for (auto &it : post)
        cout << it << " ";
    cout << endl;

    return 0;
}