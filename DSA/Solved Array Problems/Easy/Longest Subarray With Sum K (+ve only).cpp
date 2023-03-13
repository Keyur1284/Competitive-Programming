// Problem Link :- https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399

// Time Complexity :- O(n)
// Space Complexity :- O(1)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    long long n = a.size(), i = 0, j = 0, maxi = 0, sum = 0;

    while (i < n)
    {
        while (j < n && sum + a[j] <= k)
            sum += a[j++];

        if (sum == k)
            maxi = max(maxi, j - i);

        sum -= a[i++];
    }

    return maxi;
}