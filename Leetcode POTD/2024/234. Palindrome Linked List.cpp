// Problem Link :- https://leetcode.com/problems/palindrome-linked-list/

// Solved by storing values in vector
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

    bool isPalindrome(ListNode* head) 
    {
        vector<int> vec;
        ListNode* node = head;
        
        while (node)
        {
            vec.emplace_back(node->val);
            node = node->next;
        }
        
        int i = 0, j = vec.size() - 1;
        
        while (i < j)
        {
            if (vec[i] != vec[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};



// Solved by storing values in stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        ListNode* node = head;

        while (node)
        {
            st.emplace(node->val);
            node = node->next;
        }

        node = head;

        while (node)
        {
            if (node->val != st.top())
                return false;

            st.pop();
            node = node->next;
        }

        return true;
    }
};



// Solved by recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n) (Due to recursion stack)

class Solution {
public:

    bool isPalindrome(ListNode* head) 
    {
        ListNode* node = head;
        return isPalindromeUtil(node, head);
    }

    bool isPalindromeUtil(ListNode*& node, ListNode* head)
    {
        if (head == NULL)
            return true;

        bool isPal = isPalindromeUtil(node, head->next);

        if (isPal && node->val == head->val)
        {
            node = node->next;
            return true;
        }

        return false;
    }
};



// Solved by reversing the first half of the linked list
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* hare = head, *tortoise = head, *prev = NULL, *nextNode;

        while (hare && hare->next)
        {
            hare = hare->next->next;

            nextNode = tortoise->next;
            tortoise->next = prev;
            prev = tortoise;
            tortoise = nextNode;
        }

        ListNode* left = prev, *right = tortoise;
        
        if (hare)
            right = right->next;

        while (left)
        {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};