// Problem Link :- https://leetcode.com/problems/find-in-mountain-array/

// Solved by Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeakIndex (MountainArray &mountainArr, int n)
    {
        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int left = mountainArr.get(mid - 1), curr = mountainArr.get(mid), right = mountainArr.get(mid + 1);

            if (left <= curr && curr >= right)
                return mid;

            if (left <= curr)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    int findTargetOnLeft (MountainArray &mountainArr, int target, int peakInd)
    {
        int low = 0, high = peakInd;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val < target)
                low = mid + 1;

            else
                high = mid - 1;
        } 

        return -1;
    }

    int findTargetOnRight (MountainArray &mountainArr, int target, int peakInd, int n)
    {
        int low = peakInd + 1, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val > target)
                low = mid + 1;

            else
                high = mid - 1;
        }  

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        
        int peakInd = findPeakIndex (mountainArr, n);
        
        int targetOnLeft = findTargetOnLeft (mountainArr, target, peakInd);

        if (targetOnLeft != -1)
            return targetOnLeft;

        int targetOnRight = findTargetOnRight (mountainArr, target, peakInd, n);
        
        return targetOnRight;
    }
};