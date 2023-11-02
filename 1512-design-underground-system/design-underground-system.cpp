// class UndergroundSystem {
// public:
//     unordered_map<int, pair<string, int>> passenger;
//     unordered_map<string, vector<int>> stationTime;
//     UndergroundSystem() {
//         unordered_map<int, pair<string, int>> passenger;
//         unordered_map<string, vector<int>> stationTime;
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         passenger[id] = make_pair(stationName, t);
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         stationTime[ passenger[id].first + '->' + stationName ].emplace_back( abs(passenger[id].second - t) ); 
//         passenger.erase(id);
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         double avg = 0;

//         for(int time: stationTime[startStation + '->' + endStation]) {
//             avg += time;
//         }

//         return avg/stationTime[startStation + '->' + endStation].size();
//     }
// };

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> passenger;
    unordered_map<string, pair<int, int>> stationTime;
    UndergroundSystem() {
        unordered_map<int, pair<string, int>> passenger;
        unordered_map<string, pair<int, int>> stationTime;
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        stationTime[ passenger[id].first + "->" + stationName ].first += abs(passenger[id].second - t);
        stationTime[ passenger[id].first + "->" + stationName ].second += 1; 
        passenger.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return double(stationTime[startStation + "->" + endStation].first)/double(stationTime[startStation + "->" + endStation].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */