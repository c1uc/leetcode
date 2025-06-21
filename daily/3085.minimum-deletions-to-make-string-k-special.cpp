#include <bits/stdc++.h>

#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int t = 0;
        for(char c : word) {
            if(!freq[c - 'a']) t++;
            freq[c - 'a']++;
        }
        int ans = word.size(), sum = 0, tot;
        sort(freq.begin(), freq.end());
        for(int i = 26 - t; i < 26; i++) {
            if(freq[i] == 0) continue;
            tot = sum + ranges::fold_left(freq | views::drop(i) | views::filter([&](int x) {return x > freq[i] + k;}) | views::transform([&](int x) {return x - (freq[i] + k);}), 0, plus<>());
            ans = min(ans, tot);
            sum += freq[i];
        }
        return ans;
    }
};
