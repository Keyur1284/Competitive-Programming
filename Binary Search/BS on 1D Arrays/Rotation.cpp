// Problem Link :- https://practice.geeksforgeeks.org/problems/rotation4723/1

// Solved by Binary Search
// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    
	    int low = 0, high = n - 1, minVal = INT_MAX, index, mid;
	    
	    while (low <= high)
	    {
	        mid = (low + high) >> 1;
	        
	        if (nums[low] <= nums[mid])
	        {
	            if (nums[low] < minVal)
	            {
	                minVal = nums[low];
	                index = low;
	            }
	            
	            low = mid + 1;
	        }
	        
	        if (nums[high] >= nums[mid])
	        {
	            if (nums[mid] < minVal)
	            {
	                minVal = nums[mid];
	                index = mid;
	            }
	            
	            high = mid - 1;
	        }
	    }
	    
	    return index;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
