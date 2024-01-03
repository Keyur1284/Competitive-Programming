// Problem Link :- https://leetcode.com/problems/maximum-subsequence-score/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();    
        long long ans = 0, sum = 0;
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(nums2[i], nums1[i]);
        }

        sort (vec.rbegin(), vec.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &it : vec)
        {
            sum += it.second;
            pq.emplace(it.second);

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
            {
                ans = max(ans, 1LL * it.first * sum);
            }
        }

        return ans;
    }
};