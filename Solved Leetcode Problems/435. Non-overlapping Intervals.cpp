// Problem Link :- https://leetcode.com/problems/non-overlapping-intervals/

// Solved greedily (Sorting by endtime)
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

bool comp (vector<int> &val1, vector<int> &val2)
{
    return val1[1] < val2[1];
}

class Solution {
public:  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        int prev = -1e6, del = 0;

        for (auto &it : intervals)
        {
            int start = it[0], end = it[1];

            if (start >= prev)
            {
                prev = end;
            }

            else
                del++;
        }

        return del;
    }
};