// Problem Link :- https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// Solved by Brute Force Approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int K)
    {
        int i = 0, j = 0, k = 0;
        int arr[n + m];

        while (i < n && j < m) 
            arr[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];

        while (i < n)
            arr[k++] = arr1[i++];

        while (j < m)
            arr[k++] = arr2[j++];
            
        return arr[K - 1];
    }
};



// Solved by Binary Search 
// Time Complexity :- O(log(min(n, m)))
// Space Complexity :- O(1)

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
            return kthElement (arr2, arr1, m, n, k);
            
        int low = max(0, k - m), high = min(k, n);
        
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];
            
            if (left1 <= right2 && left2 <= right1)
                return max(left1, left2);
                
            if (left1 > right2)
                high = cut1 - 1;
                
            else
                low = cut1 + 1;
        }
    }
};