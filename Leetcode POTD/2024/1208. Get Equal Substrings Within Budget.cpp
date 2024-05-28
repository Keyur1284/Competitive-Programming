// Problem Link :- https://leetcode.com/problems/get-equal-substrings-within-budget/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length(), availableCost = maxCost;
        int left = 0, right = 0, maxLen = 0;

        while (right < n)
        {
            int reqCost = abs(s[right] - t[right]);

            while (availableCost < reqCost && left < right)
            {
                availableCost += abs(s[left] - t[left]);
                left++;
            }
            
            if (availableCost < reqCost)
            {
                right++;
                left = right;
                availableCost = maxCost;
                continue;
            }

            availableCost -= reqCost;
            int len = right - left + 1;
            maxLen = max(len, maxLen);
            right++;
        }

        return maxLen;
    }
};



class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.length();
        int currCost = 0, maxLen = 0;

        for (int left = 0, right = 0; right < n; right++)
        {
            currCost += abs(s[right] - t[right]);

            while (currCost > maxCost && left <= right)
            {
                currCost -= abs(s[left] - t[left]);
                left++;
            }

            int len = right - left + 1;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};