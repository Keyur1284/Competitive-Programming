// Problem Link :- https://leetcode.com/problems/find-missing-observations/

// Solved by Maths
// Time Complexity :- O(max(n, m))
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int totalSum = (n + m) * mean;
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
        int requiredSum = totalSum - currentSum;

        if (requiredSum < n || requiredSum > 6*n)
            return {};

        int lostMean = requiredSum / n, mod = requiredSum % n;
            
        vector<int> lostRolls(n, lostMean);

        for (int i = 0; i < mod; i++)
            lostRolls[i]++;

        return lostRolls;
    }
};