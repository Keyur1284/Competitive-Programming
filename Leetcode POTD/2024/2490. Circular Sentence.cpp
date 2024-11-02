// Problem Link :- https://leetcode.com/problems/circular-sentence/

// Solved using stringstream
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool isCircularSentence(string sentence) {

        stringstream ss(sentence);
        string word;
        vector<string> words;
        
        while (ss >> word)
            words.emplace_back(word);
        
        int n = words.size();
        char last = words[n - 1].back();

        for (int i = 0; i < n; i++) 
        {
            if (words[i].front() != last) 
                return false;
            
            last = words[i].back();
        }

        return true;
    }
};



// Solved without using extra space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n = sentence.length();

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        }

        return sentence[0] == sentence[n - 1];
    }
};