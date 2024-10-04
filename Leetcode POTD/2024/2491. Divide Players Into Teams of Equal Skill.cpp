// Problem Link :- https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();

        if (n & 1)
            return -1;

        sort(skill.begin(), skill.end());
        int skillSum = skill[0] + skill[n - 1];
        long long chemSum = 1LL * skill[0] * skill[n - 1];

        for (int i = 1; i < n/2; i++)
        {
            if (skill[i] + skill[n - i - 1] != skillSum)
                return -1;

            chemSum += 1LL * skill[i] * skill[n - i - 1];
        }

        return chemSum;
    }
};



// Solved by Freq Vector
// Time Complexity :- O(n)
// Space Complexity :- O(1000)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size(), totalSkill = 0;
        vector<int> skillFrequency(1001, 0);

        for (int playerSkill : skill) 
        {
            totalSkill += playerSkill;
            skillFrequency[playerSkill]++;
        }

        if (totalSkill % (n / 2) != 0)
            return -1;

        int targetTeamSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        for (int playerSkill : skill) 
        {
            int partnerSkill = targetTeamSkill - playerSkill;

            if (skillFrequency[partnerSkill] == 0)
                return -1;

            totalChemistry += 1LL * playerSkill * partnerSkill;
            skillFrequency[partnerSkill]--;
        }

        return totalChemistry / 2;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size(), totalSkill = 0;
        unordered_map<int, int> skillMap;

        for (int playerSkill : skill) 
        {
            totalSkill += playerSkill;
            skillMap[playerSkill]++;
        }

        if (totalSkill % (n / 2) != 0)
            return -1;

        int targetSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        for (auto& [currSkill, currFreq] : skillMap) 
        {
            int partnerSkill = targetSkill - currSkill;

            if (!skillMap.count(partnerSkill) || currFreq != skillMap[partnerSkill])
                return -1;

            totalChemistry += 1LL * currSkill * partnerSkill * currFreq;
        }

        return totalChemistry / 2;
    }
};