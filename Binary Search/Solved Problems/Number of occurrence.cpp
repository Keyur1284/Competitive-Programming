// Problem Link :- https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Search

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    int first = -1, last = -1, low = 0, high = n - 1, ans = n, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }

            else 
                low = mid + 1;
        }

        if (ans == n || arr[ans] != x)
            return 0;

        first = ans;

        low = 0, high = n - 1, ans = n;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (arr[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }

            else 
                high = mid - 1;
        }

        last = ans;

        return (last - first + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends



// Solved by inbuilt lower_bound and upper_bound functions

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    int first = lower_bound (arr, arr + n, x) - arr;
        
        if (first >= n || arr[first] != x)
            return 0;

        int last = upper_bound (arr, arr + n, x) - arr;

        return (last - 1 - first + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends