// Problem Link :- https://leetcode.com/problems/add-two-numbers-ii/

// Solved by reversing the linked list
// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    ListNode* reverse (ListNode* head)
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* revHead1 = reverse(l1);
        ListNode* revHead2 = reverse(l2);

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;

        while (revHead1 || revHead2 || carry)
        {
            int sum = carry;

            if (revHead1)
            {
                sum += revHead1->val;
                revHead1 = revHead1->next;
            }

            if (revHead2)
            {
                sum += revHead2->val;
                revHead2 = revHead2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;
            temp->next = new ListNode(digit);
            temp = temp->next;
        }

        ListNode* ans = reverse(head->next);

        return ans;
    }
};



// Solved using stack
// Time Complexity :- O(N)
// Space Complexity :- O(N)

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

    void pushNodes (ListNode* head, stack<int> &st)
    {
        while (head)
        {
            st.emplace(head->val);
            head = head->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> st1, st2, addition;

        pushNodes (l1, st1);
        pushNodes (l2, st2);

        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry)
        {
            int sum = carry;

            if (!st1.empty())
            {
                sum += st1.top();
                st1.pop();
            }
            
            if (!st2.empty())
            {
                sum += st2.top();
                st2.pop();
            }

            int digit = sum % 10;
            carry = sum / 10;
            addition.emplace(digit);
        }

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while (!addition.empty())
        {
            temp->next = new ListNode(addition.top());
            temp = temp->next;
            addition.pop();
        }

        return head->next;
    }
};