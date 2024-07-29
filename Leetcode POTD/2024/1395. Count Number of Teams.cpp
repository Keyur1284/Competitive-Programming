// Problem Link :- https://leetcode.com/problems/count-number-of-teams/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0;
        vector<vector<int>> increasingCache(n, vector<int>(4, -1)), decreasingCache(n, vector<int>(4, -1));

        for (int startIndex = 0; startIndex < n; startIndex++) 
        {
            int increasingTeams = countIncreasingTeams(startIndex, 1, n, increasingCache, rating);
            int decreasingTeams = countDecreasingTeams(startIndex, 1, n, decreasingCache, rating);
            teams += increasingTeams + decreasingTeams;
        }

        return teams;
    }

private:
    int countIncreasingTeams(int currentIndex, int teamSize, int n, vector<vector<int>>& increasingCache, const vector<int>& rating) {

        if (teamSize == 3) 
            return 1;

        if (increasingCache[currentIndex][teamSize] != -1)
            return increasingCache[currentIndex][teamSize];

        int validTeams = 0;

        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) 
        {
            if (rating[nextIndex] > rating[currentIndex]) 
            {
                validTeams += countIncreasingTeams(nextIndex, teamSize + 1, n, increasingCache, rating);
            }
        }

        return increasingCache[currentIndex][teamSize] = validTeams;
    }

    int countDecreasingTeams(int currentIndex, int teamSize, int n, vector<vector<int>>& decreasingCache, const vector<int>& rating) {

        if (teamSize == 3) 
            return 1;

        if (decreasingCache[currentIndex][teamSize] != -1)
            return decreasingCache[currentIndex][teamSize];

        int validTeams = 0;

        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) 
        {
            if (rating[nextIndex] < rating[currentIndex]) 
            {
                validTeams += countDecreasingTeams(nextIndex, teamSize + 1, n, decreasingCache, rating);
            }
        }

        return decreasingCache[currentIndex][teamSize] = validTeams;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0;
        vector<vector<int>> increasingCache(n, vector<int>(4, 0)), decreasingCache(n, vector<int>(4, 0));

        for (int startIndex = n - 1; startIndex >= 0; startIndex--) 
        {
            increasingCache[startIndex][1] = 1;
            decreasingCache[startIndex][1] = 1;
        }

        for (int startIndex = n - 2; startIndex >= 0; startIndex--) 
        {
            for (int teamSize = 2; teamSize <= 3; teamSize++) 
            {
                for (int nextIndex = startIndex + 1; nextIndex < n; nextIndex++) 
                {
                    if (rating[nextIndex] > rating[startIndex]) 
                    {
                        increasingCache[startIndex][teamSize] += increasingCache[nextIndex][teamSize - 1];
                    }

                    else if (rating[nextIndex] < rating[startIndex]) 
                    {
                        decreasingCache[startIndex][teamSize] += decreasingCache[nextIndex][teamSize - 1];
                    }
                }
            }
        }

        for (int startIndex = 0; startIndex < n; startIndex++) 
        {
            teams += increasingCache[startIndex][3] + decreasingCache[startIndex][3];
        }

        return teams;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0;

        for (int mid = 0; mid < n; mid++) 
        {
            int leftSmaller = 0, rightLarger = 0;

            for (int left = mid - 1; left >= 0; left--) 
            {
                leftSmaller += rating[left] < rating[mid];
            }

            for (int right = mid + 1; right < n; right++) 
            {
                rightLarger += rating[right] > rating[mid];
            }

            teams += leftSmaller * rightLarger;

            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightLarger;

            teams += leftLarger * rightSmaller;
        }

        return teams;
    }
};



// Solved by BIT
// Time Complexity :- O(nlog(maxRating))
// Space Complexity :- O(maxRating)

class BIT {
public:

    int n;
    vector<int> bit;

    BIT (int n) 
    {
        this->n = n;
        bit.resize(n + 1);
    }

    void update(int index, int value)
    {
        while (index <= n)
        {
            bit[index] += value;
            index += index & -index;
        }
    }

    int query(int index)
    {
        int sum = 0;

        while (index > 0)
        {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0, maxRating = *max_element(rating.begin(), rating.end());
        BIT left(maxRating), right(maxRating);

        for (auto &it : rating)
        {
            right.update(it, 1);
        }
        
        for (auto &it : rating)
        {
            right.update(it, -1);

            int leftSmaller = left.query(it - 1);
            int rightSmaller = right.query(it - 1);
            int leftLarger = left.query(maxRating) - left.query(it);
            int rightLarger = right.query(maxRating) - right.query(it);

            teams += leftSmaller * rightLarger + leftLarger * rightSmaller;

            left.update(it, 1);
        }

        return teams;
    }
};



// Solved by Policy Based Data Structure
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename type, typename comp = less<type>>
using ordered_set = tree<type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0;
        ordered_set<int> left, right;

        for (auto &it : rating)
        {
            right.insert(it);
        }

        for (auto &it : rating)
        {
            right.erase(it);

            int leftSmaller = left.order_of_key(it);
            int rightSmaller = right.order_of_key(it);
            int leftLarger = left.size() - left.order_of_key(it);
            int rightLarger = right.size() - right.order_of_key(it);

            teams += leftSmaller * rightLarger + leftLarger * rightSmaller;

            left.insert(it);
        }

        return teams;
    }
};



// Solved by BIT (Coordinate Compression)
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class BIT {
public:

    int n;
    vector<int> bit;

    BIT (int n) 
    {
        this->n = n;
        bit.resize(n + 1);
    }

    void update(int index, int value)
    {
        while (index <= n)
        {
            bit[index] += value;
            index += index & -index;
        }
    }

    int query(int index)
    {
        int sum = 0;

        while (index > 0)
        {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), teams = 0;
        vector<int> sortedRating = rating;
        sort(sortedRating.begin(), sortedRating.end());
        unordered_map<int, int> coordinateCompression;

        for (int i = 0; i < n; i++)
        {
            coordinateCompression[sortedRating[i]] = i + 1;
        }

        BIT left(n), right(n);

        for (auto &it : rating)
        {
            right.update(coordinateCompression[it], 1);
        }

        for (auto &it : rating)
        {
            right.update(coordinateCompression[it], -1);

            int leftSmaller = left.query(coordinateCompression[it] - 1);
            int rightSmaller = right.query(coordinateCompression[it] - 1);
            int leftLarger = left.query(n) - left.query(coordinateCompression[it]);
            int rightLarger = right.query(n) - right.query(coordinateCompression[it]);

            teams += leftSmaller * rightLarger + leftLarger * rightSmaller;

            left.update(coordinateCompression[it], 1);
        }

        return teams;
    }
};