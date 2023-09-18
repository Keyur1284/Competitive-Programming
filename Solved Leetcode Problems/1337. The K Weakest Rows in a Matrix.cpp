// Problem Link :- https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Solved by Binary Search and Sorting
// Time Complexity :- O(mlogn + mlogm + k)
// Space Complexity :- O(m)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> ones;

        for (int i = 0; i < m; i++)
        {
            int index = n - (lower_bound(mat[i].rbegin(), mat[i].rend(), 1) - mat[i].rbegin());
            ones.emplace_back(index, i);
        }

        sort(ones.begin(), ones.end());

        vector<int> weak;

        for (int i = 0; i < k; i++)
            weak.emplace_back(ones[i].second);

        return weak;
    }
};



// Solved by Binary Search and Priority Queue
// Time Complexity :- O(mlogn + klogk)
// Space Complexity :- O(m)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++)
        {
            int index = n - (lower_bound(mat[i].rbegin(), mat[i].rend(), 1) - mat[i].rbegin());
            pq.emplace(index, i);

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> weak;

        while (!pq.empty())
        {
            weak.emplace_back(pq.top().second);
            pq.pop();
        }

        reverse(weak.begin(), weak.end());

        return weak;
    }
};
