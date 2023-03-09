// Description of approach
// 1. Insert the element at the correct position in the sorted array
// 2. Repeat the above steps for the remaining array

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void insertion_sort (vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
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
    
    insertion_sort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}