// Problem Link :- https://leetcode.com/problems/calculate-money-in-leetcode-bank/

// Solved by Simulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int totalMoney(int n) {
        
        int ans = 0, monday = 1;
        
        while (n > 0) 
        {
            for (int day = 0; day < min(n, 7); day++)
                ans += monday + day;
            
            n -= 7;
            monday++;
        }
        
        return ans;
    }
};



// Solved by Maths
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int totalMoney(int n) {
        
        int weeks = n / 7, days = n % 7;
        
        return (28 * weeks) + (7 * (weeks - 1) * weeks / 2) + (weeks * days) + (days * (days + 1) / 2);
    }
};



class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7, first = 28, last = 28 + (k - 1) * 7;
        int arithmeticSum = k * (first + last) / 2;
    
        int monday = 1 + k, finalWeek = 0;

        for (int day = 0; day < n % 7; day++) 
            finalWeek += monday + day;
        
        return arithmeticSum + finalWeek;
    }
};