// Problem Link :- https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

// Solved by Back-tracking
// Time Complexity :- O(2^totalReq * n)
// Space Complexity :- O(totalReq + n)

class Solution {
public:

    int maxReq = 0;

    void solve (int index, int count, vector<int> &buildings, int &totalReq, int &n, vector<vector<int>>& requests)
    {
        if (index == totalReq)
        {
            for (auto &it : buildings)
            {
                if (it)
                    return;
            }

            maxReq = max(maxReq, count);
            return;
        }

        int from = requests[index][0], to = requests[index][1];

        buildings[from]--;
        buildings[to]++;

        solve (index + 1, count + 1, buildings, totalReq, n, requests);

        buildings[to]--;
        buildings[from]++;

        solve (index + 1, count, buildings, totalReq, n, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int totalReq = requests.size();
        vector<int> buildings(n, 0);

        solve (0, 0, buildings, totalReq, n, requests);

        return maxReq;
    }
};



// Solved by Bit-manipulation
// Time Complexity :- O(2^totalReq * n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int maxReq = 0, totalReq = requests.size();

        for (int mask = 0; mask < (1 << totalReq); mask++)
        {
            int index = 0;
            int bitCount = __builtin_popcount(mask);

            if (bitCount <= maxReq) 
                continue;

            vector<int> buildings(n, 0);

            for (int currMask = mask; currMask > 0; currMask >>= 1, index++)
            {
                if (currMask & 1)
                {
                    int from = requests[index][0], to = requests[index][1];

                    buildings[from]--;
                    buildings[to]++;
                }
            }

            bool flag = true;

            for (auto &it : buildings)
            {
                if (it)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                maxReq = bitCount;
        }

        return maxReq;
    }
};