// Problem Link :- https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Solved by Prefix XOR
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        vector<int> prefXor = arr;
        prefXor.insert(prefXor.begin(), 0);
        int n = prefXor.size();

        for (int i = 1; i < n; i++)
        {
            prefXor[i] ^= prefXor[i - 1];
        }

        int triplets = 0;

        for (int start = 0; start < n; start++)
        {
            for (int end = start + 1; end < n; end++)
            {
                if (prefXor[start] == prefXor[end])
                {
                    triplets += end - start - 1;
                }
            }
        }

        return triplets;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        unordered_map<int, int> freq, prefXor;
        int n = arr.size();
        int triplets = 0;
        int xorVal = 0;

        freq[0] = 1;

        for (int i = 0; i < n; i++)
        {
            xorVal ^= arr[i];
            triplets += freq[xorVal] * i - prefXor[xorVal];
            freq[xorVal]++;
            prefXor[xorVal] += i + 1;
        }

        return triplets;
    }
};