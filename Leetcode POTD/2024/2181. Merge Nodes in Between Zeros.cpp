// Problem Link :- https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Solved by two pointers
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
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *curr = head, *temp = head->next, *prev = NULL;

        while (temp)
        {
            int sum = 0;

            while (temp && temp->val)
            {
                sum += temp->val;
                temp = temp->next;
            }

            curr->val = sum;
            curr->next = temp;
            prev = curr;
            curr = curr->next;
            temp = temp->next;
        }

        prev->next = NULL;
        return head;
    }
};



class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* modify = head->next, *nextSum = modify;

        while (nextSum) 
        {
            int sum = 0;

            while (nextSum->val) 
            {
                sum = sum + nextSum->val;
                nextSum = nextSum->next;
            }

            modify->val = sum;
            nextSum = nextSum->next;
            modify->next = nextSum;
            modify = modify->next;
        }

        return head->next;
    }
};



// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        head = head->next;
        
        if (head == NULL)
            return head;
        
        ListNode* temp = head;
        int sum = 0;
        while (temp->val != 0) 
        {
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};