// Problem Link :- https://leetcode.com/problems/copy-list-with-random-pointer/

// Solved by using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> vis;

    Node* copyRandomList(Node* head) {
        
        if (head == NULL)
            return NULL;

        if (vis.find(head) != vis.end())
            return vis[head];

        Node* newHead = new Node (head->val);
        vis[head] = newHead;
        newHead->next = copyRandomList (head->next);
        newHead->random = copyRandomList (head->random);

        return newHead;
    }
};


// Solved by using dummy node
// Time Complexity :- O(n)
// Space Complexity :- O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        
        while (curr)
        {
            Node* copy = new Node (curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        Node* fast = head;

        while (fast)
        {
            if (fast->random)
                fast->next->random = fast->random->next;
            
            fast = fast->next->next;
        }

        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* prev = head;
        Node* front;

        while (prev)
        {
            front = prev->next->next;
            temp->next = prev->next;
            temp = temp->next;
            prev->next = front;
            prev = front;
        }

        return dummy->next;
    }
};