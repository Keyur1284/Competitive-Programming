// Problem Link :- https://leetcode.com/problems/maximum-score-from-removing-substrings/

// Solved using vector as stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int n = s.length(), gainAB = 0, gainBA = 0;
        bool takeAB = (x >= y), takeBA = (y >= x);
        vector<int> st;

        if (takeAB)
        {
            st.clear();

            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'b' && !st.empty() && s[st.back()] == 'a')
                {
                    s[i] = '$';
                    s[st.back()] = '$';
                    st.pop_back();
                    gainAB += x;
                    continue;
                }
                
                st.emplace_back(i);
            }

            st.clear();

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '$')
                    continue;

                if (s[i] == 'a' && !st.empty() && s[st.back()] == 'b')
                {
                    st.pop_back();
                    gainAB += y;
                    continue;
                }

                st.emplace_back(i);
            }
        }

        if (takeBA)
        {
            st.clear();
            
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a' && !st.empty() && s[st.back()] == 'b')
                {
                    s[i] = '$';
                    s[st.back()] = '$';
                    st.pop_back();
                    gainBA += y;
                    continue;
                }
                
                st.emplace_back(i);
            }

            st.clear();

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '$')
                    continue;

                if (s[i] == 'b' && !st.empty() && s[st.back()] == 'a')
                {
                    st.pop_back();
                    gainBA += x;
                    continue;
                }

                st.emplace_back(i);
            }
        }

        return max(gainAB, gainBA);
    }
};



// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int n = s.length(), totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount = (n - stringAfterFirstPass.length()) / 2;

        totalScore += removedPairsCount * max(x, y);

        string stringAfterSecondPass = removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount = (stringAfterFirstPass.length() - stringAfterSecondPass.length()) / 2;

        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        
        stack<char> charStack;

        for (char currentChar : input) 
        {
            if (currentChar == targetPair[1] && !charStack.empty() && charStack.top() == targetPair[0])
                charStack.pop();
            
            else
                charStack.push(currentChar);
        }

        string remainingChars;
        
        while (!charStack.empty()) 
        {
            remainingChars += charStack.top();
            charStack.pop();
        }
        
        reverse(remainingChars.begin(), remainingChars.end());
        
        return remainingChars;
    }
};



// Solved using two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int totalPoints = 0;

        if (x > y) 
        {
            totalPoints += removeSubstring(s, "ab", x);
            totalPoints += removeSubstring(s, "ba", y);
        }
        
        else 
        {
            totalPoints += removeSubstring(s, "ba", y);
            totalPoints += removeSubstring(s, "ab", x);
        }

        return totalPoints;
    }

    int removeSubstring(string& inputString, string targetSubstring, int pointsPerRemoval) {
        
        int n = inputString.length();
        int totalPoints = 0, writeIndex = 0;

        for (int readIndex = 0; readIndex < n; readIndex++) 
        {
            inputString[writeIndex++] = inputString[readIndex];

            if (writeIndex > 1 && inputString[writeIndex - 2] == targetSubstring[0] && inputString[writeIndex - 1] == targetSubstring[1])
            {
                writeIndex -= 2;
                totalPoints += pointsPerRemoval;
            }
        }

        inputString.erase(inputString.begin() + writeIndex, inputString.end());

        return totalPoints;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if (x < y)
        {    
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int n = s.length(), aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == 'a')
                ++aCount;

            else if (s[i] == 'b') 
            {
                if (aCount > 0)
                {
                    aCount--;
                    totalPoints += x;
                } 
                
                else 
                    bCount++;
            } 
            
            else 
            {
                totalPoints += min(bCount, aCount) * y;
                aCount = bCount = 0;
            }
        }

        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};