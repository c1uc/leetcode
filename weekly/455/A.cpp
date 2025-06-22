#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi prime(1000001, 1);

auto init = []() {
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= 1000000; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= 1000000; j += i) prime[j] = 0;
        }
    }
    return 'c';
}();

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vi freq(101, 0);
        for(int num : nums) freq[num]++;
        for(int i = 0; i <= 100; i++) {
            if(freq[i] && prime[freq[i]]) return true;
        }
        return false;
    }
};
