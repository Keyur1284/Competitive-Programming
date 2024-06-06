// Problem Link :- https://leetcode.com/problems/hand-of-straights/

// Solved using map
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int handSize = hand.size();

        if (handSize % groupSize)
            return false;

        map<int, int> cardCount;

        for (auto &card : hand)
            cardCount[card]++;

        while (!cardCount.empty())
        {
            auto card = cardCount.begin();
            int num = card->first;
            
            for (int k = 0; k < groupSize; k++)
            {
                if (!cardCount.count(num + k))
                    return false;

                cardCount[num + k]--;

                if (cardCount[num + k] == 0)
                    cardCount.erase(num + k);
            }
        }

        return true;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int handSize = hand.size();

        if (handSize % groupSize)
            return false;

        unordered_map<int, int> cardCount;
        
        for (auto &card : hand)
            cardCount[card]++;

        for (auto &card : hand) 
        {
            int startCard = card;

            while (cardCount[startCard - 1])
                startCard--;

            while (startCard <= card) 
            {
                while (cardCount[startCard]) 
                {
                    for (int nextCard = startCard; nextCard < startCard + groupSize; nextCard++) 
                    {
                        if (!cardCount[nextCard])
                            return false;
                        
                        cardCount[nextCard]--;
                    }
                }

                startCard++;
            }
        }

        return true;
    }
};