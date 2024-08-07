// Problem Link :- https://leetcode.com/problems/integer-to-english-words/

// Solved using recursion
// Time Complexity :- O(log_10(n))
// Space Complexity :- O(log_10(n))

class Solution {
public:

    const vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        return convertToWords(num);
    }

private:

    string convertToWords(int num) {
        
        if (num < 10)
            return belowTen[num];
        
        if (num < 20) 
            return belowTwenty[num - 10];
        
        if (num < 100) 
            return belowHundred[num / 10] + (num % 10 ? " " + convertToWords(num % 10) : "");
        
        if (num < 1000) 
            return convertToWords(num / 100) + " Hundred" + (num % 100 ? " " + convertToWords(num % 100) : "");
        
        if (num < 1000000)
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 ? " " + convertToWords(num % 1000) : "");
        
        if (num < 1000000000)
            return convertToWords(num / 1000000) + " Million" + (num % 1000000 ? " " + convertToWords(num % 1000000) : "");
        
        return convertToWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + convertToWords(num % 1000000000) : "");
    }
};



// Solved using Iterative approach
// Time Complexity :- O(log_10(n))
// Space Complexity :- O(log_10(n))

class Solution {
public:

    unordered_map<int, string> ones = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}},
    tens = {{1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}},
    radix = {{3, "Billion"}, {2, "Million"}, {1, "Thousand"}};

    string getEnglishWord(int num)
    {
        if (ones.count(num))
            return ones[num];

        int currNum = 0, radix = 1;
        string one, ten, hundred;

        while(num)
        {
            int digit = num % 10;
            num /= 10;
            currNum = currNum + digit * radix;
            radix *= 10;

            if (one.empty())
                one = (digit == 0 ? "$$" : ones[digit]);

            else if (ten.empty())
            {
                if (ones.count(currNum) && currNum > 10 && currNum < 20)
                {
                    ten = ones[currNum];
                    one = "$$";
                }

                else
                    ten = (digit == 0 ? "$$" : tens[digit]);
            }

            else if (hundred.empty())
                hundred = ones[digit];
        }

        string ans = hundred.empty() ? "" : hundred + " Hundred";
        ans += ten == "$$" || ten.empty() ? "" : (ans.empty() ? "" : " ") + ten;
        ans += one == "$$" || one.empty() ? "" : (ans.empty() ? "" : " ") + one;
        return ans;
    }

    string numberToWords(int num) {
        
        if (num == 0)
            return "Zero";

         vector<string> numStrings;

        string s;
        int temp = num;

        while(temp)
        {
            int digit = temp % 10;
            temp /= 10;

            s += digit + '0';

            if (s.length() == 3 || temp == 0)
            {
                reverse(s.begin(), s.end());
                numStrings.emplace_back(s);
                s = "";
            }
        }

        vector<string> ans;

        for (auto &it : numStrings)
            ans.emplace_back(getEnglishWord(stoi(it)));

        int n = ans.size();
        string englishWord;

        for (int i = 0; i < n; i++)
        {
            string curr = ans[i];

            if (i != 0 && !ans[i].empty())
                curr += " " + radix[i];

            if (!curr.empty())
                englishWord = curr + (englishWord.empty() ? "" : " ") + englishWord;
        }

        return englishWord; 
    }
};