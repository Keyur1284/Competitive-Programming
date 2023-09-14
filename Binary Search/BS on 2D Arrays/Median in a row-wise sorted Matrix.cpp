// Problem Link :- https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// Solved by Binary Search
// Time Complexity :- O(32 * R * logC)
// Space Complexity :- O(1)

//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (int i = 0; i < r; i++)
        {
            mini = min (mini, matrix[i][0]);
            maxi = max (maxi, matrix[i][c - 1]);
        }
        
        int low = mini, high = maxi, req = (r * c)/2, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            int pos = 0;
            
            for (int i = 0; i < r; i++)
            {
                pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
 
            if (pos > req)
            {
                ans = mid;
                high = mid - 1;
            }
                
            else
                low = mid + 1;
        }
        
        return ans;
    }
};