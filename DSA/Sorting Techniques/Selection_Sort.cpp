// Description of approach
// 1. Find the minimum element in the array
// 2. Swap the minimum element with the first element
// 3. Repeat the above steps for the remaining array

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    selection_sort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}