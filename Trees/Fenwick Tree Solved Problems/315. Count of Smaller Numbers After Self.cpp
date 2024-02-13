// Problem Link :- https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Solved using Fenwick Tree (Binary Indexed Tree)
// Time Complexity :- O(nlogn) for building the BIT and O(logn) for each query and update operation
// Space Complexity :- O(n)
// Here n = 2 * 10^4

class BIT {

    int n;
    vector<int> bit;

public:

    BIT (int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update (int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query (int id)
    {
        int sum = 0;

        while (id > 0)
        {
            sum += bit[id];
            id -= (id & -id);
        }

        return sum;
    }
};

class Solution {
public:
    
    int getIndex(int ind)
    {
        return ind + 1e4 + 1;
    }

    vector<int> countSmaller(vector<int>& nums) {
        
        BIT bit(2 * 1e4 + 1);
        vector<int> counts;

        for (auto &it : nums)
        {
            // Increasing the frequency of current number by 1
            bit.update(getIndex(it), 1);
        }

        for (auto &it : nums)
        {
            // Getting the count of numbers smaller than the current number
            int smallerCount = bit.query(getIndex(it - 1));
            counts.emplace_back(smallerCount);

            // Decreasing the frequency of current number by 1
            bit.update(getIndex(it), -1);
        }

        return counts;
    }
};



// Solved using Fenwick Tree (Binary Indexed Tree)
// Time Complexity :- O(klogk) for building the BIT and O(logn) for each query and update operation
// Space Complexity :- O(k)
// Where k = max(nums) - min(nums) + 1

class BIT {

    int n;
    vector<int> bit;

public:

    BIT (int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update (int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query (int id)
    {
        int sum = 0;

        while (id > 0)
        {
            sum += bit[id];
            id -= (id & -id);
        }

        return sum;
    }
};

class Solution {
public:
    
    int maxVal = INT_MIN, minVal = INT_MAX;

    int getIndex(int ind)
    {
        return ind - minVal + 1;
    }

    vector<int> countSmaller(vector<int>& nums) {
        
        for (auto &it : nums)
        {
            maxVal = max(maxVal, it);
            minVal = min(minVal, it);
        }
        
        int len = maxVal - minVal + 1;

        BIT bit(len);
        vector<int> counts;


        for (auto &it : nums)
        {
            bit.update(getIndex(it), 1);
        }

        for (auto &it : nums)
        {
            int smallerCount = bit.query(getIndex(it - 1));
            counts.emplace_back(smallerCount);

            bit.update(getIndex(it), -1);
        }

        return counts;
    }
};



// Solved using Policy Based Data Structure (Ordered Set)
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> counts(n);
        ordered_set<int> os;

        for (int i = n - 1; i >= 0; i--)
        {
            int smallerCount = os.order_of_key(nums[i]);
            counts[i] = smallerCount;
            
            os.insert(nums[i]);
        }

        return counts;
    }
};