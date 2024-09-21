// Problem Link :- https://leetcode.com/problems/lexicographical-numbers/

// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    vector<int> order;

    void DFS(int num, int n)
    {
        order.emplace_back(num);

        for (int next = 0; next < 10; next++)
        {
            if (num * 10 + next > n)
                return;

            DFS(num * 10 + next, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        
        for (int start = 1; start <= min(n, 9); start++)
            DFS(start, n);

        return order;
    }
};