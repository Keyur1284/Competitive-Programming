// Description of Heap Sort
// 1. Build a max heap from the input data.
// 2. At this point, the largest item is stored at the root of the heap. 
// Replace it with the last item of the heap followed by reducing the size of heap by 1. 
// Finally, heapify the root of the tree.
// 3. Repeat step 2 while size of heap is greater than 1.

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void heapify (vector<int> &arr, int n, int largest)
{
    int index = largest;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (index != largest)
    {
        swap (arr[index], arr[largest]);
        heapify (arr, n, largest);
    }
}

void heap_sort (vector<int> &arr, int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify (arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap (arr[0], arr[i]);
        heapify (arr, i, 0);
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
    
    heap_sort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}