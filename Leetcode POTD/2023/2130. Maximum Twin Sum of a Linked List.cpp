// Problem Link :- https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by storing all values in a vector

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
    int pairSum(ListNode* head) {
        
        vector<int> nums;

        while (head)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }

        int n = nums.size(), maxSum = 0;

        for (int i = 0; i < n/2; i++)
        {
            maxSum = max(maxSum, nums[i] + nums[n - 1 - i]);
        }

        return maxSum;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

// Solved by reversing second half of the linked list

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
    int pairSum(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *nextNode, *prev = NULL;

        while (slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode *front = head, *back = prev;
        int maxSum = 0;

        while (back)
        {
            maxSum = max(maxSum, front->val + back->val);
            front = front->next;
            back = back->next;
        }

        return maxSum;
    }
};


// Solved by reversing first half of the linked list

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
    int pairSum(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        ListNode *nextNode, *prev = NULL;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maxSum = 0;
        ListNode* left = prev, *right = nextNode;

        while (right)
        {
            maxSum = max(maxSum, left->val + right->val);    
            right = right->next;
            left = left->next;
        }

        return maxSum;
    }
};