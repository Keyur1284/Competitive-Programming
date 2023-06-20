// Problem Link :- https://practice.geeksforgeeks.org/problems/square-root/0

// Solved by Binary Search
// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long low = 1, high = x, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            long long square = mid * mid;
            
            if (square == x)
                return mid;
                
            if (square < x)
            {
                ans = mid;
                low = mid + 1;
            }
                
            else
                high = mid - 1;
        }
        
        return ans;
    }
};