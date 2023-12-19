// Problem Link :- https://leetcode.com/problems/image-smoother/

// Solved by brute force approach
// Time Complexity :- O(n * m * 9)
// Space Complexity :- O(n * m)

class Solution {
public:

    bool isValid(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(), n = img[0].size();

        vector<vector<int>> smooth(m, vector<int> (n));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int sum = 0, count = 0;

                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int x = row + dx, y = col + dy;

                        if (isValid(x, y, m, n))
                        {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }

                smooth[row][col] = sum/count;
            }
        }

        return smooth;
    }
};



// Solved by Math (without using extra space)
// Time Complexity :- O(n * m * 9)
// Space Complexity :- O(1)

class Solution {
public:

    bool isValid(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(), n = img[0].size();

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int sum = 0, count = 0;

                for (int x = row - 1; x <= row + 1; x++)
                {
                    for (int y = col - 1; y <= col + 1; y++)
                    {
                        if (isValid(x, y, m, n))
                        {
                            sum += img[x][y] % 256;
                            count++;
                        }
                    }
                }

                img[row][col] += (sum / count) * 256;
            }
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                img[row][col] /= 256;
            }
        }

        return img;
    }
};



// Solved by Bit Manipulation (without using extra space)
// Time Complexity :- O(n * m * 9)
// Space Complexity :- O(1)

class Solution {
public:

    bool isValid(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(), n = img[0].size();

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int sum = 0, count = 0;

                for (int x = row - 1; x <= row + 1; x++)
                {
                    for (int y = col - 1; y <= col + 1; y++)
                    {
                        if (isValid(x, y, m, n))
                        {
                            sum += img[x][y] & 255;
                            count++;
                        }
                    }
                }

                img[row][col] |= (sum / count) << 8;
            }
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                img[row][col] >>= 8;
            }
        }

        return img;
    }
};