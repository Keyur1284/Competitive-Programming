// Problem Link :- https://www.codingninjas.com/codestudio/problems/implement-upper-bound_8165383

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Search

int upperBound(vector<int> &arr, int x, int n){
	
	int low = 0, high = n - 1, ans = n, mid;

	while (low <= high)
	{
		mid = (low + high) >> 1;

		if (arr[mid] > x)
		{
			ans = mid;
			high = mid - 1;
		}

		else
			low = mid + 1;
	}

	return ans;
}


// Solved by using inbuilt upper_bound function

int upperBound(vector<int> &arr, int x, int n){
	
	int index = upper_bound (arr.begin(), arr.end(), x) - arr.begin();

	return index;
}