// Problem Link :- https://leetcode.com/problems/build-an-array-with-stack-operations/

// Solved by brute force approach
// Time Compleixty :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> operations;
        int size = target.size();

        for (int num = 1, j = 0; num <= n && j < size; num++)
        {
            operations.emplace_back("Push");
            
            if (num == target[j])
                j++;

            else
            operations.emplace_back("Pop");
        }

        return operations;
    }
};