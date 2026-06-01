class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        for(auto x: asteroids) {
            if(mass < x) return false;
            mass = mass > 1e5 ? 1e5 : mass + x;
        }
        return true;
    }
};
