// Problem Link :- https://leetcode.com/problems/spiral-matrix-iv/

// Solved by Simulation
// Time Complexity :- O(m * n)
// Space Complexity :- O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m, vector<int> (n, -1));
        int left = 0, top = 0, right = n - 1, bottom = m - 1;

        while (head && left <= right && top <= bottom)
        {
            for (int i = left; head && i <= right; i++)
            {
                matrix[top][i] = head->val;
                head = head->next;
            }

            top++;

            for (int i = top; head && i <= bottom; i++)
            {
                matrix[i][right] = head->val;
                head = head->next;
            }

            right--;

            if (top <= bottom)
            {
                for (int i = right; head && i >= left; i--)
                {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }

                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; head && i >= top; i--)
                {
                    matrix[i][left] = head->val;
                    head = head->next;
                }

                left++;
            }
        }

        return matrix;
    }
};



class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        int i = 0, j = 0, dir = 0, movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));

        for (; head; head = head->next) 
        {
            res[i][j] = head->val;
            int newi = i + movement[dir][0], newj = j + movement[dir][1];
            
            if (min(newi, newj) < 0 || newi >= m || newj >= n || res[newi][newj] != -1)
                dir = (dir + 1) % 4;

            i += movement[dir][0];
            j += movement[dir][1];
        }

        return res;
    }
};