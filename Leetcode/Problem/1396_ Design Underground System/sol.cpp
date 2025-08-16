class UndergroundSystem {
public:
    unordered_map<string,unordered_map<string,vector<int>>> m;
    unordered_map<int,pair<string,int>> in; 
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> curr=in[id];
        m[curr.first][stationName].push_back(t-curr.second);
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> curr=m[startStation][endStation];
        double ans=0;
        for(int i=0; i< curr.size(); i++)
        {
            ans+=curr[i];
        }
        return ans/curr.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */