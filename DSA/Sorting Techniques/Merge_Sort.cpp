// Description of approach
// 1. Divide the array into two halves
// 2. Sort the two halves recursively
// 3. Merge the two sorted halves

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge (vector<int> &arr, int start, int mid, int end)
{
    int l = start, r = mid + 1, size = end - start + 1, index = 0;
    vector<int> temp(size);

    while (l <= mid && r <= end)
        temp[index++] = (arr[l] < arr[r])? arr[l++] : arr[r++];

    while (l <= mid)
        temp[index++] = arr[l++];

    while (r <= end)
        temp[index++] = arr[r++];

    for (int i = 0; i < size; i++)
        arr[start + i] = temp[i];
}

void merge (vector<int> &arr, int start, int mid, int end)
{
    int l = start, r = mid + 1, size = end - start + 1;
    vector<int> temp(size);

    for (int i = 0; i < size; i++)
    {
        if (l == mid + 1)
            temp[i] = arr[r++];

        else if (r == end + 1)
            temp[i] = arr[l++];

        else
            temp[i] = (arr[l] < arr[r])? arr[l++] : arr[r++];
    }

    for (int i = 0; i < size; i++)
        arr[start + i] = temp[i];
}

void merge_sort (vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
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
    
    merge_sort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}