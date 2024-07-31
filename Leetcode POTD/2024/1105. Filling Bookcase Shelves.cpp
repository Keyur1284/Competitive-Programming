// Problem Link :- https://leetcode.com/problems/filling-bookcase-shelves/

// Solved by Memoization Method
// Time Complexity :- O(n * shelfWidth)
// Space Complexity :- O(n * shelfWidth)

class Solution {
public:

    int solve(int index, int remWidth, int maxHeight, int n, int shelfWidth, vector<vector<int>>& books, vector<vector<int>> &dp)
    {
        if (index == n)
            return maxHeight;

        int currWidth = books[index][0], currHeight = books[index][1];

        if (dp[index][remWidth] != -1)
            return dp[index][remWidth];

        int sameShelf = INT_MAX, newShelf = INT_MAX;

        if (currWidth <= remWidth)
            sameShelf = solve(index + 1, remWidth - currWidth, max(maxHeight, currHeight), n, shelfWidth, books, dp);

        newShelf = maxHeight + solve(index + 1, shelfWidth - currWidth, currHeight, n, shelfWidth, books, dp);

        return dp[index][remWidth] = min(sameShelf, newShelf);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));

        return solve(0, shelfWidth, 0, n, shelfWidth, books, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * shelfWidth)
// Space Complexity :- O(n)

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) 
        {
            int remWidth = shelfWidth, maxHeight = 0, j = i - 1;

            while (j >= 0 && remWidth >= books[j][0]) 
            {
                remWidth -= books[j][0];
                maxHeight = max(maxHeight, books[j][1]);
                dp[i] = min(dp[i], dp[j] + maxHeight);
                j--;
            }
        }

        return dp[n];
    }
};