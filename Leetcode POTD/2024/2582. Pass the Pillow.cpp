// Problem Link :- https://leetcode.com/problems/pass-the-pillow/

// Solved by Simulation
// Time Complexity :- O(time)
// Space Complexity :- O(1)

class Solution {
public:
    int passThePillow(int n, int time) {
        
        int pos = 1;

        for (int t = 1, dir = -1; t <= time; t++)
        {
            if (pos == 1 || pos == n)
                dir *= -1;

            pos += dir;
        }

        return pos;
    }
};



// Solved by Math
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int passThePillow(int n, int time) {

        int fullRounds = time / (n - 1), extraTime = time % (n - 1);
        return (fullRounds % 2 == 0) ? 1 + extraTime : n - extraTime;
    }
};