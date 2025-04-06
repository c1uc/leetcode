#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int INF = 1e9;

class Router {
public:
    int memoryLimit;
    queue<vector<int>> packets;
    set<vector<int>, greater<vector<int>>> allPackets;
    unordered_map<int, vector<int>> packetTimestamps;
    unordered_map<int, int> poppedCount;
    
    Router(int ml) : memoryLimit(ml) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> v = {source, destination, timestamp};
        if (allPackets.count(v)) {
            return false;
        }

        if (packets.size() >= memoryLimit) {
            auto v = packets.front();
            packets.pop();

            allPackets.erase(v);
            poppedCount[v[1]]++;
        }

        packets.push(v);
        allPackets.emplace(v);
        packetTimestamps[v[1]].emplace_back(v[2]);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {};
        }

        auto v = packets.front();
        packets.pop();
        allPackets.erase(v);

        poppedCount[v[1]]++;
        return v;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = packetTimestamps.find(destination);
        if (it == packetTimestamps.end()) {
            return 0;
        }

        auto& s = it->second;
        
        int low = lower_bound(s.begin() + poppedCount[destination], s.end(), startTime) - s.begin();
        int high = upper_bound(s.begin() + poppedCount[destination], s.end(), endTime) - s.begin();
        return high - low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */