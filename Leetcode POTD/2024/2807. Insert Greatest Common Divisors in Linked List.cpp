// Problem Link :- https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

// Solved by Simulation
// Time Complexity :- O(n * log(min(a, b)))
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* currNode = head;

        while (currNode->next)
        {
            ListNode* nextNode = currNode->next;
            int hcf = __gcd(currNode->val, nextNode->val);
            ListNode* gcdNode = new ListNode(hcf, nextNode);
            currNode->next = gcdNode;
            currNode = nextNode;
        }

        return head;
    }
};