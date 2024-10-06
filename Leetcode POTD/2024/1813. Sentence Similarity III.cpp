// Problem Link :- https://leetcode.com/problems/sentence-similarity-iii/

// Solved using deque
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:

    deque<string> extractWords(string &sentence)
    {
        stringstream ss(sentence);
        deque<string> words;
        string word;

        while(ss >> word)
            words.emplace_back(word);

        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        deque<string> words1 = extractWords(sentence1), words2 = extractWords(sentence2);

        while (!words1.empty() && !words2.empty() && words1.front() == words2.front())
        {
            words1.pop_front();
            words2.pop_front();
        }

        while (!words1.empty() && !words2.empty() && words1.back() == words2.back())
        {
            words1.pop_back();
            words2.pop_back();
        }

        return words1.empty() || words2.empty();
    }
};



// Solved by Two Pointer Approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:

    vector<string> extractWords(string &sentence)
    {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        while(ss >> word)
            words.emplace_back(word);

        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> words1 = extractWords(sentence1), words2 = extractWords(sentence2);

        if (words1.size() > words2.size())
            swap(words1, words2);

        int start = 0, end1 = words1.size() - 1, end2 = words2.size() - 1;

        while (start <= end1 && words1[start] == words2[start])
            start++;

        while (end1 >= start && words1[end1] == words2[end2])
            end1--, end2--;

        return end1 < start;
    }
};