// Problem Link :- https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

// Solved by Brute Force Approach
// Time Complexity :- O(n * k) where k is the average length of the string
// Space Complexity :- O(1)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size(), minTime = 0, mt = -1, pt = -1, gt = -1;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && i < n - 1)
                travel[i] += travel[i - 1];

            int m = count(garbage[i].begin(), garbage[i].end(), 'M');
            int p = count(garbage[i].begin(), garbage[i].end(), 'P');
            int g = count(garbage[i].begin(), garbage[i].end(), 'G');

            minTime += m + p + g;

            if (m > 0)
                mt = i;

            if (p > 0)
                pt = i;

            if (g > 0)
                gt = i;
        }   

        if (mt > 0)
            minTime += travel[mt - 1];

        if (pt > 0)
            minTime += travel[pt - 1];

        if (gt > 0)
            minTime += travel[gt - 1];         

        return minTime;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n * k) where k is the average length of the string
// Space Complexity :- O(1)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size(), minTime = 0;
        unordered_map<char, int> lastPos;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && i < n - 1)
                travel[i] += travel[i - 1];

            for (auto &c : garbage[i])
                lastPos[c] = i;

            minTime += garbage[i].length();
        }   

        string garbageTypes = "MPG";
        
        for (auto &c : garbageTypes) 
        {
            minTime += (lastPos[c] == 0 ? 0 : travel[lastPos[c] - 1]);
        }
        
        return minTime;
    }
};