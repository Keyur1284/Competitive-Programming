// Problem Link :- https://leetcode.com/problems/split-linked-list-in-parts/

// Solved by Linear Traversal
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

    int countNodes (ListNode* head)
    {
        int nodes = 0;

        while(head)
        {
            nodes++;
            head = head->next;
        }

        return nodes;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> parts(k, NULL);
        int count = countNodes(head);

        int div = count/k, rem = count % k;
        ListNode* curr = head, *prev = NULL;
        
        for (int i = 0; i < k; i++, rem--)
        {
            parts[i] = curr;

            for (int j = 0; j < div + (rem > 0); j++)
            {
                prev = curr;
                curr = curr->next;
            }

            if (prev)
                prev->next = NULL;
        }

        return parts;
    }
};