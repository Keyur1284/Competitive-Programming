//Problem Link :- https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688

#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {

    int maxi = INT_MIN;
    vector <int> dp1 (n, 1), dp2 (n, 1);
    
    for (int index = 0; index < n; index++)
    {
        for (int prev = 0; prev < index; prev++)
        {
            if (arr[index] > arr[prev] && 1 + dp1[prev] > dp1[index])
                dp1[index] = 1 + dp1[prev];
        }
    }
    
    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev = n - 1; prev > index; prev--)
        {
            if (arr[index] > arr[prev] && 1 + dp2[prev] > dp2[index])
                dp2[index] = 1 + dp2[prev];
        }
        
        maxi = max (maxi, dp1[index] + dp2[index] - 1);
    }
    
    return maxi;
} 
