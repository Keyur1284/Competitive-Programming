// Problem Link :- https://leetcode.com/problems/non-overlapping-intervals/

// Solved by Sorting
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



class Solution {
public:  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int nonOverlapCount = 1, minEnd = INT_MAX;

        for (auto &interval : intervals)
        {
            if (interval[0] >= minEnd)
            {
                nonOverlapCount++;
                minEnd = interval[1];
            }

            else
            {
                minEnd = min(minEnd, interval[1]);
            }
        }

        return intervals.size() - nonOverlapCount;
    }
};



class Solution {
public:  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int overlapCount = -1, minEnd = INT_MAX;

        for (auto &interval : intervals)
        {
            if (interval[0] >= minEnd)
            {
                minEnd = interval[1];
            }

            else
            {
                overlapCount++;
                minEnd = min(minEnd, interval[1]);
            }
        }

        return overlapCount;
    }
};



class Solution {
public:  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int overlapCount = 0, minEnd = INT_MAX;

        for (auto &interval : intervals)
        {
            if (interval[0] >= minEnd)
            {
                minEnd = interval[1];
            }

            else
            {
                overlapCount += (minEnd != INT_MAX);
                minEnd = min(minEnd, interval[1]);
            }
        }

        return overlapCount;
    }
};



class Solution {
public:  

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int overlapCount = 0, minEnd = INT_MAX;

        for (auto &interval : intervals)
        {
            if (interval[0] >= minEnd)
            {
                minEnd = interval[1];
            }

            else
            {
                overlapCount++;
                minEnd = min(minEnd, interval[1]);
            }
        }

        return overlapCount - 1;
    }
};