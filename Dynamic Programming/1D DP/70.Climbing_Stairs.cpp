//Problem Link :- https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        
        if (n <= 2)
           return n;
        
        int prev = 2, prev2 = 1, ans;
        for (int i = 3; i<=n; i++)
        {
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        
        return ans;
    }
};