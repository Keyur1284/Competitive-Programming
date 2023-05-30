// Problem Link :- https://practice.geeksforgeeks.org/problems/burning-tree/1

// Time Complexity :- O(N)
// Space Complexity :- O(N)

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int targetData;
    Node* targetNode = NULL;
    
    unordered_map<Node*, Node*> parent;
    unordered_set<Node*> vis;
    
    void findPar (Node* node, Node* par)
    {
        if (node == NULL)
            return;
            
        if (par)
            parent[node] = par;
            
        if (node->data == targetData)
            targetNode = node;
        
        findPar(node->left, node);
        findPar(node->right, node);
    }
    
    int minTime(Node* root, int target) 
    {
        this->targetData = target;
        findPar(root, NULL);
        
        queue<Node*> BFS;
        BFS.emplace(targetNode);
        vis.emplace(targetNode);
        int time = 0;
        
        while (!BFS.empty())
        {
            int size = BFS.size();
            bool flag = false;
            
            while (size--)
            {
                Node* node = BFS.front();
                BFS.pop();
                
                if (node->left && vis.find(node->left) == vis.end())
                {
                    flag = true;
                    BFS.emplace(node->left);
                    vis.emplace(node->left);
                }
                
                if (node->right && vis.find(node->right) == vis.end())
                {
                    flag = true;
                    BFS.emplace(node->right);
                    vis.emplace(node->right);
                }
                
                if (parent.find(node) != parent.end() && vis.find(parent[node]) == vis.end())
                {
                    flag = true;
                    BFS.emplace(parent[node]);
                    vis.emplace(parent[node]);
                }
            }
            
            if (flag)
                time++;
        }
        
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends