#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int max_odd = 0, min_even = s.length();
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 0) {
                if (!freq[i]) continue;
                min_even = min(min_even, freq[i]);
            } else {
                max_odd = max(max_odd, freq[i]);
            }
        }
        return max_odd - min_even;
    }
};
