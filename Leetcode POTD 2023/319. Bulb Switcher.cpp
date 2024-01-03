// Problem Link :- https://leetcode.com/problems/bulb-switcher/

// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int bulbSwitch(int n) {
        
        long long low = 1, high = n, mid, ans = 0;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (mid * mid == n)
                return mid;

            if (mid * mid < n)
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }
};


// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int bulbSwitch(int n) {
        
        return sqrt(n);
    }
};