// Description of Quick Sort :
// Quick Sort is a Divide and Conquer algorithm. 
// It picks an element as pivot and partitions the given array around the picked pivot.
// There are many different versions of quickSort that pick pivot in different ways.
// 1) Always pick first element as pivot.
// 2) Always pick last element as pivot.
// 3) Pick a random element as pivot.
// 4) Pick median as pivot.
// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

// Code of Quick Sort by keeping pivot as first element

int partition (vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
            i++;

        while (j > low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Code of Quick Sort by keeping pivot as end;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}


void quick_sort (vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    quick_sort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}

