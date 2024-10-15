// Problem Link :- https://leetcode.com/problems/separate-black-and-white-balls/

// Solved by Two Pointer Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    long long minimumSteps(string s) {
        
        int whitePosition = 0, n = s.length();
        long long totalSwaps = 0;

        for (int currentPos = 0; currentPos < n; currentPos++) 
        {
            if (s[currentPos] == '0') 
            {
                totalSwaps += currentPos - whitePosition;
                whitePosition++;
            }
        }

        return totalSwaps;
    }
};



class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwaps = 0;
        int blackBallCount = 0;

        for (auto ch : s)
        {
            if (ch == '0')
                totalSwaps += blackBallCount;

            else
                blackBallCount++;
        }

        return totalSwaps;
    }
};