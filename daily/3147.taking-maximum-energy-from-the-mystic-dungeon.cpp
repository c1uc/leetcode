#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maximumEnergy(vector<int>& energy, int k) {
            for(int i = energy.size() - k - 1;i >= 0;i--) {
                energy[i] += energy[i + k];
            }
            return *max_element(energy.begin(), energy.end());
        }
    };
