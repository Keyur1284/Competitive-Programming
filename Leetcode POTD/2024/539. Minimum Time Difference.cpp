// Problem Link :- https://leetcode.com/problems/minimum-time-difference/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int n = timePoints.size();
        vector<int> timeInMin(n);

        for (int i = 0; i < n; i++)
        {
            int hours = stoi(timePoints[i].substr(0, 2)), minutes = stoi(timePoints[i].substr(3, 2));
            timeInMin[i] = hours * 60 + minutes;
        }

        int minDiff = 24 * 60;
        sort(timeInMin.begin(), timeInMin.end());

        for (int i = 0; i < n - 1; i++)
        {
            int diff = timeInMin[i + 1] - timeInMin[i];
            minDiff = min(diff, minDiff);
        }

        minDiff = min(minDiff, timeInMin[0] + 24 * 60 - timeInMin[n - 1]);

        return minDiff;
    }
};



// Solved by Bucket Sort
// Time Complexity :- O(n)
// Space Complexity :- O(24 * 60)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> timeInMin(24 * 60, 0);

        for (string time : timePoints)
        {
            int hours = stoi(time.substr(0, 2)), minutes = stoi(time.substr(3, 2));
            
            if (timeInMin[hours * 60 + minutes] == 1)
                return 0;
            
            timeInMin[hours * 60 + minutes] = 1;
        }

        int minDiff = 24 * 60, prev = -1, first = -1;

        for (int i = 0; i < 24 * 60; i++)
        {
            if (timeInMin[i] == 1)
            {
                if (prev != -1)
                    minDiff = min(minDiff, i - prev);
                
                if (first == -1)
                    first = i;
                
                prev = i;
            }
        }

        minDiff = min(minDiff, first + 24 * 60 - prev);

        return minDiff;
    }
};