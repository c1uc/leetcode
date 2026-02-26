#include <bit>
using namespace std;
vector<vector<string>> res(11);

auto _ = []() {
    for(unsigned h = 0;h < 12;h++) {
        for(unsigned m = 0;m < 60;m++) {
            int c = popcount(h) + popcount(m);
            stringstream ss;
            res[c].push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
        }
    }
    return 'c';
}();

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        return res[turnedOn];
    }
};
