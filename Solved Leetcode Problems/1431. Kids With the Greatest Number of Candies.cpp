// Problem Link :- https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> result(n);

        for (int i = 0; i < n; i++)
        {
            result[i] = (candies[i] + extraCandies >= maxi);
        }

        return result;
    }
};