// Problem Link :- https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_5713505

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

int getLongestSubarray(vector<int>& nums, int k){
    
    map<int, int> mp;
    int sum = 0, maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
            maxi = max(maxi, i + 1);

        if (mp.find(sum - k) != mp.end())
        {
            int len = i - mp[sum - k];
            maxi = max(maxi, len);
        }

        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return maxi;
}