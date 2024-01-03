// Problem Link :- https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<int> ans, lis;

        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();

            if (it == lis.size())
                lis.emplace_back(obstacles[i]);

            else
                lis[it] = obstacles[i];

            ans.emplace_back(it + 1);
        }

        return ans;
    }
};