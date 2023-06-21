// Problem Link :- https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

// Solved by Binary Search
// Time Complexity :- O(n*log(m))
// Space Complexity :- O(1)

class Solution{
	public:
	
	long long power (long long base, long long exp, long long num)
	{
	    long long ans = 1;
	    
	    for (int i = 1; i <= exp; i++)
	    {
	        ans *= base;
	        
	        if (ans > num)
	            break;
	    }
	    
	    return ans;
	}
	
	int NthRoot(int n, int m)
	{
	    long long low = 1, high = m, mid, ans = -1;

        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            long long res = power (mid, n, m);
            
            if (res == m)
            {
                ans = mid;
                break;
            }
    
            else if (res < m)
                low = mid + 1;
    
            else  
                high = mid - 1;
        }
    
        return ans;
	}  
};