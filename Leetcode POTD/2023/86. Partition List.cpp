// Problem Link :- https://leetcode.com/problems/partition-list/

// Solved by using extra space
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
    ListNode* partition(ListNode* head, int x) {
        
        vector<ListNode*> le, geq;
        ListNode* curr = head;

        while(curr)
        {
            if (curr->val < x)
                le.emplace_back(curr);

            else
                geq.emplace_back(curr);

            curr = curr->next;
        }

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        for (auto &it : le)
        {
            temp->next = it;
            temp = temp->next;
        }

        for (auto &it : geq)
        {
            temp->next = it;
            temp = temp->next;
        }

        temp->next = NULL;
        return newHead->next;
    }
};



// Solved in one pass without using extra space
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* le = new ListNode(0);
        ListNode* geq = new ListNode(0);
        ListNode* curr = head, *small = le, *big = geq;

        while(curr)
        {
            if (curr->val < x)
            {
                small->next = curr;
                small = small->next;
            }
                
            else
            {
                big->next = curr;
                big = big->next;
            }

            curr = curr->next;
        }

        small->next = geq->next;
        big->next = NULL;

        return le->next;
    }
};