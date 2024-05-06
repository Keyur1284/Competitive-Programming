// Problem Link :- https://leetcode.com/problems/remove-nodes-from-linked-list/

// Solved using Stack and Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void solve(ListNode* node, stack<ListNode*> &st, ListNode* &prev)
    {
        if (node == NULL)
            return;

        st.emplace(node);
        solve(node->next, st, prev);

        if (prev == NULL || st.top()->val >= prev->val)
        {
            ListNode* node = st.top();
            node->next = prev;
            prev = node;
        }

        st.pop();
    }

    ListNode* removeNodes(ListNode* head) {
        
        stack<ListNode*> st;
        ListNode* prev = NULL;

        solve(head, st, prev);

        return prev;
    }
};



// Solved using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        stack<ListNode*> st;
        ListNode* node = head, *prev = NULL;

        while (node)
        {
            st.emplace(node);
            node = node->next;
        }

        while (!st.empty())
        {
            if (prev == NULL || st.top()->val >= prev->val)
            {
                ListNode* node = st.top();
                node->next = prev;
                prev = node;
            }

            st.pop();
        }

        return prev;
    }
};

// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* nextNode = removeNodes(head->next);

        if (head->val < nextNode->val)
        {
            delete head;
            return nextNode;
        }

        head->next = nextNode;
        return head; 
    }
};



// Solved by Reversing the Linked List
// Time Complexity :- O(2 * n)
// Space Complexity :- O(1)

class Solution {
public:

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head;

        while (curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        
        head = reverseList(head);

        ListNode* node = head, *prev = NULL;

        while (node)
        {
            ListNode* nextNode = node->next;
            
            if (prev == NULL || node->val >= prev->val)
                prev = node;

            else
                prev->next = nextNode;
            
            node = nextNode;
        }

        return reverseList(head);
    }
};