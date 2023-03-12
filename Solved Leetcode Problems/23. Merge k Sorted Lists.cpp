// Problem Link :- https://leetcode.com/problems/merge-k-sorted-lists/

// Time Complexity :- O(nlogk)
// Space Complexity :- O(k)

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue <int, vector<int>, greater<int>> nodes;

        for (auto &it : lists)
        {
            while (it)
            {
                nodes.emplace(it->val);
                it = it->next;
            }
        }

        if(nodes.empty())
            return NULL;

        ListNode* temp = new ListNode(nodes.top());
        nodes.pop();

        ListNode* head = temp;

        while(!nodes.empty())
        {
            int node = nodes.top();
            nodes.pop();

            temp->next = new ListNode(node);
            temp = temp->next;
        }

        return head;
    }
};


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> nodes;

        for (auto &it : lists)
        {
            while (it)
            {
                nodes.emplace_back(it->val);
                it = it->next;
            }
        }

        sort(nodes.rbegin(), nodes.rend());

        ListNode* head = NULL;

        for (auto &it : nodes)
        {
            head = new ListNode(it, head);
        }
        
        return head;
    }
};


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

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while (left && right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }

            else
            {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        while (left)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }

        while (right)
        {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }

        return head->next;
    }

    ListNode* mergeSort (vector<ListNode*>& lists, int start, int end)
    {
        if (start == end)
            return lists[start];

        int mid = (start + end) >> 1;
        
        ListNode* left = mergeSort(lists, start, mid);
        ListNode* right = mergeSort(lists, mid + 1, end); 

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty())
            return NULL;

        int n = lists.size();

        return mergeSort(lists, 0, n - 1);
    }
};