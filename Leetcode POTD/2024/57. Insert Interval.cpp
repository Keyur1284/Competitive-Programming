// Problem Link :- https://leetcode.com/problems/insert-interval/

// Solved by Binary Search
// Time Complexity :- O(n + logn)
// Space Complexity :- O(n)

class Solution {
public:

    void insertion (vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        auto index = upper_bound (intervals.begin(), intervals.end(), newInterval) - intervals.begin();

        if (index == intervals.size())
            intervals.emplace_back(newInterval);

        else
            intervals.insert(intervals.begin() + index, newInterval);
    }

    bool isOverlapping (vector<int> &a, vector<int> &b)
    {
        return (min(a[1], b[1]) - max(a[0], b[0]) >= 0);
    }

    vector <int> merge (vector<int> &a, vector<int> &b)
    {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> answer;

        insertion (intervals, newInterval);

        int n = intervals.size();

        for (int i = 0; i < n; i++)
        {
            vector<int> temp = {intervals[i][0], intervals[i][1]};

            while (i < n && isOverlapping(temp, intervals[i]))
            {
                temp = merge(temp, intervals[i]);
                i++;
            }

            i--;
            answer.emplace_back(temp);
        }

        return answer;
        
    }
};