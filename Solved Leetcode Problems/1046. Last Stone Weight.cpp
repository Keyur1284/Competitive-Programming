// Problem Link :- https://leetcode.com/problems/last-stone-weight/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for (auto &it : stones)
            pq.emplace(it);

        while (!pq.empty())
        {
            if (pq.size() == 1)
                return pq.top();

            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();

            if (num1 != num2)
                pq.emplace(num1 - num2);
        }

        return 0;
    }
};