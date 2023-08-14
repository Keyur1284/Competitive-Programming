// Problem Link :- https://www.codingninjas.com/studio/problems/row-with-maximum-1-s_1112656

// Solved by Binary Search
// Time Complexity :- O(nlogm)
// Space Complexity :- O(1)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    
    int index = -1, maxOnes = 0;

    for (int i = 0; i < n; i++)
    {
        int ones = m - (lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin());
        
        if (ones > maxOnes)
        {
            maxOnes = ones;
            index = i;
        }
    }

    return index;
}



int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    
    int index = -1, maxOnes = 0;

    for (int i = 0; i < n; i++)
    {
        int ones = m - (upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin());
        
        if (ones > maxOnes)
        {
            maxOnes = ones;
            index = i;
        }
    }

    return index;
}