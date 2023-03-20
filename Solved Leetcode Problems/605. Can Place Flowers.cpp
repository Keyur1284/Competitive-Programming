// Problem Link :- https://leetcode.com/problems/can-place-flowers/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int m = flowerbed.size(), count = 0;
        
        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool left = (i == 0) || (flowerbed[i - 1] == 0);
                bool right = (i == m - 1) || (flowerbed[i + 1] == 0);

                if (left && right)
                {
                    flowerbed[i] = 1;
                    count++;
                }
            }

            if (count == n)
                return true;
        }
        
        return (count >= n);
    }
};