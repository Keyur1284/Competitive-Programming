// Problem Link :- https://www.codingninjas.com/codestudio/problems/lower-bound_8165382

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Search

int lowerBound(vector<int> arr, int n, int x) {
	
	int low = 0, high = n - 1, ans = n, mid;

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

	return ans;
}


// Solved by using inbuilt lower_bound function

int lowerBound(vector<int> arr, int n, int x) {
	
	int index = lower_bound (arr.begin(), arr.end(), x) - arr.begin();

	return index;
}
