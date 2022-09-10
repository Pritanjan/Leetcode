// https://leetcode.com/problems/design-underground-system/
// bloomberg's interviews question

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>>  checkInM ;
    unordered_map<string, pair<int,int>> checkOutM ;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInM[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& checkIn = checkInM[id];
        string path = checkIn.first + "_" + stationName ;
        checkOutM[path].first  += t - checkIn.second;
        checkOutM[path].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "_" + endStation;
        auto& checkOut = checkOutM[path];
        return (double) checkOut.first / checkOut.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

