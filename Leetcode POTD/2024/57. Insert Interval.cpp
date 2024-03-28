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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        insertion (intervals, newInterval);

        vector<vector<int>> answer;
        
        for (auto &interval : intervals) 
        {
            if (answer.empty() || answer.back()[1] < interval[0]) 
                answer.push_back(interval);

            else 
                answer.back()[1] = max(answer.back()[1], interval[1]);
        }

        return answer;
    }
};



// Solved by Linear Search
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size(), i = 0;
        vector<vector<int>> finalIntervals;

        while (i < n && intervals[i][1] < newInterval[0]) 
        {
            finalIntervals.emplace_back(intervals[i++]);
        }    
        
        while (i < n && newInterval[1] >= intervals[i][0]) 
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        finalIntervals.emplace_back(newInterval);
        
        while (i < n)
        {
            finalIntervals.emplace_back(intervals[i++]);
        }

        return finalIntervals;
    }
};