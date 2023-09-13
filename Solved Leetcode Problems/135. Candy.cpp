// Problem Link :- https://leetcode.com/problems/candy/

// Solved greedily in two passes
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        int totalCandies = accumulate(candies.begin(), candies.end(), 0);

        return totalCandies;
    }
};



// Solved greedily in one pass
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int candies = 1, up = 0, peak = 0, down = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int prev = ratings[i], curr = ratings[i + 1];

            if (prev < curr)
            {
                up++;
                peak = up;
                down = 0;
                candies += 1 + up;
            }

            else if (prev == curr)
            {
                up = 0;
                down = 0;
                peak = 0;
                candies += 1;
            }

            else
            {
                down++;
                up = 0;
                candies += 1 + down;

                if (peak >= down)
                    candies--;
            }
        }

        return candies;
    }
};