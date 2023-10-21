// Problem Link :- https://leetcode.com/problems/flatten-nested-list-iterator/

// Solved by Recursion
// Time Complexity :- O(n)
// Space Complexity :- O(n)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:

    vector<int> flattened;
    int index;

    vector<int> flatten (vector<NestedInteger> &nestedList)
    {
        vector<int> ans;

        for (auto &it : nestedList)
        {
            if (it.isInteger())
                ans.emplace_back(it.getInteger());

            else
            {
                vector<int> subList = flatten(it.getList());
                ans.insert(ans.end(), subList.begin(), subList.end());
            }
        }

        return ans;
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        
        flattened = flatten(nestedList);
        index = 0;
    }
    
    int next() {
        
        return flattened[index++];
    }
    
    bool hasNext() {
        
        return index < flattened.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */