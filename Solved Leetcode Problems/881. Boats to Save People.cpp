// Problem Link :- https://leetcode.com/problems/boats-to-save-people/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());

        int low = 0, high = people.size() - 1, ans = 0;

        while (low <= high)
        {
            ans++;

            if (people[low] + people[high] <= limit)
                low++;

            high--;
        }

        return ans;
    }
};


// Time Complexity :- O(limit)
// Space Complexity :- O(limit)

// Solved using Count Sort

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        vector<int> freq(limit + 1, 0);

        for (auto &it : people)
            freq[it]++;

        for (int weight = 1, index = 0; weight <= limit; weight++)
        {
            while(freq[weight]--)
                people[index++] = weight;
        }

        int low = 0, high = people.size() - 1, ans = 0;

        while (low <= high)
        {
            ans++;

            if (people[low] + people[high] <= limit)
                low++;

            high--;
        }

        return ans;
    }
};