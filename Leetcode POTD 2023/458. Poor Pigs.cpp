// Problem Link :- https://leetcode.com/problems/poor-pigs/

// Solved using Math
// Time Complexity :- O(log2(buckets))
// Space Complexity :- O(1)

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int choice = minutesToTest/minutesToDie + 1;
        int pigs = ceil(log2(buckets)/log2(choice));

        return pigs;
    }
};



class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int pigs = 0;
        int choice = minutesToTest/minutesToDie + 1;
        
        while(pow(choice, pigs) < buckets)
            pigs++;
        
        return pigs;
    }
};