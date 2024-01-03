// Problem Link :- https://leetcode.com/problems/sort-vowels-in-a-string/

// Solved using multiset
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    bool isVowel(char ch) 
    { 
        string vowels = "aeiouAEIOU"; 
        return (vowels.find(ch) != string::npos); 
    } 

    string sortVowels(string s) {
        
        multiset<char> vowels;

        for (auto &it : s)
        {
            if (isVowel(it))
                vowels.emplace(it);
        }

        for (auto &it : s)
        {
            if (isVowel(it))
            {
                it = *vowels.begin();
                vowels.erase(vowels.begin());
            }
        }

        return s;
    }
};



// Solved using Counting Sort
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
   
    bool isVowel(char ch) 
    { 
        string vowels = "aeiouAEIOU"; 
        return (vowels.find(ch) != string::npos); 
    } 
    
    string sortVowels(string s) {
        
        unordered_map<char, int> count;

        for (auto &it : s) 
        {
            if (isVowel(it))
                count[it]++;
        }

        string sortedVowel = "AEIOUaeiou", ans;
        int j = 0;

        for (auto &it : s) 
        {
            if (!isVowel(it))
                ans += it;
            
            else 
            {
                while (count[sortedVowel[j]] == 0)
                    j++;

                ans += sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        
        return ans;
    }
};