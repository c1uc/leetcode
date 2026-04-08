class Robot {
public:
    int dist, len, w, h;
    Robot(int w, int h): dist(0), len(2 * w + 2 * h - 4), w(w), h(h) {}
    
    void step(int num) {
        dist += num;
        dist %= len;
        if (dist == 0) dist = len;
    }
    
    vector<int> getPos() {
        if (dist <= w - 1) return {dist, 0};
        if (dist <= w + h - 2) return {w - 1, dist - (w - 1)};
        if (dist <= 2 * w + h - 3) return {2 * w + h - 3 - dist, h - 1};
        return {0, len - dist};
    }
    
    string getDir() {
        if (dist == 0) return "East";
        if (dist <= w - 1) return "East";
        if (dist <= w + h - 2) return "North";
        if (dist <= 2 * w + h - 3) return "West";
        return "South";
    }
};
