// Problem Link :- https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] != diff)
                return false;
        }

        return true;
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();
        unordered_set <int> nums;
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (auto &it : arr)
        {
            mini = min(mini, it);
            maxi = max(maxi, it);
            nums.emplace(it);
        }

        if (maxi == mini)
            return true;

        if ((maxi - mini) % (n - 1))
            return false;

        int diff = (maxi - mini) / (n - 1);

        for (auto &it : arr)
        {
            if ((it - mini) % diff)
                return false;
        }

        return (nums.size() == n);
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (auto &it : arr)
        {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        if (maxi == mini)
            return true;

        if ((maxi - mini) % (n - 1))
            return false;

        int diff = (maxi - mini) / (n - 1);

        int i = 0;

        while (i < n)
        {
            if (arr[i] == mini + i * diff)
                i++;

            else if ((arr[i] - mini) % diff)
                return false;

            else
            {
                int j = (arr[i] - mini) / diff;

                if (arr[i] == arr[j])
                    return false;

                swap (arr[i], arr[j]);
            }
        }

        return true;
    }
};