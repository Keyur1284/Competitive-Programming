// Problem Link :- https://leetcode.com/problems/swap-nodes-in-pairs/

// Solved by Recursive Approach

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

    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        
        return temp;    
    }
};

// Solved by Iterative Approach

// Time Complexity :- O(n)
// Space Complexity :- O(1)


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

    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* dummy = new ListNode();

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return dummy->next;    
    }
};