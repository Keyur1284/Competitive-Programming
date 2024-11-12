// Problem Link :- https://leetcode.com/problems/most-beautiful-item-for-each-query/

// Solved by Sorting + Binary Search
// Time Complexity :- O((n + q) * log(n))
// Space Complexity :- O(log(n))

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size(), q = queries.size();
        sort(items.begin(), items.end());
        vector<int> answer(q, 0);

        for (int i = 1; i < n; i++)
            items[i][1] = max(items[i - 1][1], items[i][1]);

        for (int i = 0; i < q; i++)
        {
            vector<int> query = {queries[i], INT_MAX};
            int index = upper_bound(items.begin(), items.end(), query) - items.begin();

            if (index - 1 >= 0 && items[index - 1][0] <= queries[i])
                answer[i] = items[index - 1][1];
        }

        return answer;
    }
};