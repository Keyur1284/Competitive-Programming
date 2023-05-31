// Problem Link :- https://leetcode.com/problems/design-underground-system/

// Time Complexity : O(1)
// Space Complexity : O(N) 

class UndergroundSystem {
public:

    unordered_map<int, pair<string, int>> passenger;
    unordered_map<string, unordered_map<string, int>> tripTime;
    unordered_map<string, unordered_map<string, int>> tripCount;

    UndergroundSystem() {
        
        passenger.clear();
        tripTime.clear();
        tripCount.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        
        passenger[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        
        string startStation = passenger[id].first;
        int startTime = passenger[id].second;
        passenger.erase(id);

        tripTime[startStation][stationName] += (t - startTime);
        tripCount[startStation][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double ans = tripTime[startStation][endStation] * 1.0 / tripCount[startStation][endStation];
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
