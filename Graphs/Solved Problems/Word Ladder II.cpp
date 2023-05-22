// Problem Link :- https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

// Solved by BFS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        vector<vector<string>> sequences;
        vector<string> usedOnLevel;
        queue<vector<string>> BFS;
        
        usedOnLevel.emplace_back(beginWord);
        BFS.emplace(usedOnLevel);
        int level = 1;
        
        while (!BFS.empty())
        {
            auto words = BFS.front();
            BFS.pop();
            
            string word = words.back();
            
            if (word == endWord)
            {
                if (sequences.empty() || sequences[0].size() == words.size())
                    sequences.emplace_back(words);
            }
            
            if (words.size() == level)
            {
                for (auto &it : usedOnLevel)
                    dict.erase(it);
                    
                usedOnLevel.clear();
                level++;
            }
            
            if (word == endWord)
                continue;
                
            for (int index = 0; index < word.size(); index++)
            {
                char old = word[index];
                
                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[index] = k;
                    
                    if (dict.find(word) != dict.end())
                    {
                        words.emplace_back(word);
                        usedOnLevel.emplace_back(word);
                        BFS.emplace(words);
                        words.pop_back();
                    }
                }
                
                word[index] = old;
            }
        }
        
        return sequences;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends