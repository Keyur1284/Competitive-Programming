// Problem Link :- https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/

// Solved using Fenwick Tree (Binary Indexed Tree) (Coordinate Compression)
// Time Complexity :- O(nlogn) for building the BIT and O(logn) for each query and update operation
// Space Complexity :- O(n)

class BIT {

    int n;
    vector<int> bit;

public:

    BIT (int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int id, int val)
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

    map<int, int> index;

    void addElement(int element, vector<int> &arr, BIT &bit)
    {
        arr.emplace_back(element);
        bit.update(index[element], 1);
    }

    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();

        for (auto &it : nums)
            index[it] = 0;

        int i = 1;

        for (auto &it : index)
            it.second = i++;

        BIT bit1(n), bit2(n);
        vector<int> arr1, arr2;

        addElement(nums[0], arr1, bit1);
        addElement(nums[1], arr2, bit2);

        auto greaterCount = [&](int element, vector<int> &arr, BIT &bit)
        {
            return arr.size() - bit.query(index[element]);
        };

        for (int i = 2; i < n; i++)
        {
            int greaterCount1 = greaterCount(nums[i], arr1, bit1);
            int greaterCount2 = greaterCount(nums[i], arr2, bit2);

            if (greaterCount1 > greaterCount2)
                addElement(nums[i], arr1, bit1);

            else if (greaterCount1 < greaterCount2)
                addElement(nums[i], arr2, bit2);

            else
            {
                int m = arr1.size(), k = arr2.size();

                if (m <= k)
                    addElement(nums[i], arr1, bit1);
                
                else
                    addElement(nums[i], arr2, bit2);
            }
        }
        
        for (auto &it : arr2)
            arr1.emplace_back(it);

        return arr1;
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

    void addElement (int element, vector<int> &arr, ordered_set<int> &st)
    {
        arr.emplace_back(element);
        st.insert(element);
    }

    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr1, arr2;
        ordered_set<int> st1, st2;

        addElement(nums[0], arr1, st1);
        addElement(nums[1], arr2, st2);

        auto greaterCount = [&](int element, ordered_set<int> &st)
        {
            return st.size() - st.order_of_key(element + 1);
        };

        for (int i = 2; i < n; i++)
        {
            int greaterCount1 = greaterCount(nums[i], st1);
            int greaterCount2 = greaterCount(nums[i], st2);

            if (greaterCount1 > greaterCount2)
                addElement(nums[i], arr1, st1);

            else if (greaterCount1 < greaterCount2)
                addElement(nums[i], arr2, st2);

            else
            {
                int m = arr1.size(), k = arr2.size();

                if (m <= k)
                    addElement(nums[i], arr1, st1);
                
                else
                    addElement(nums[i], arr2, st2);
            }
        }

        for (auto &it : arr2)
            arr1.emplace_back(it);

        return arr1;
    }
};