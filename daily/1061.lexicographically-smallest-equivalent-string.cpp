#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            int n = s1.size();
            vector<int> fa(26);

            iota(fa.begin(), fa.end(), 0);
            auto find = [&](this auto&& find, int x) {
                if(fa[x] == x) return x;
                return fa[x] = find(fa[x]);
            };
            auto merge = [&](int x, int y) {
                int fx = find(x), fy = find(y);
                if(fx > fy) swap(fx, fy);
                fa[fy] = fx;
            };

            for(int i = 0; i < n; i++) {
                merge(s1[i] - 'a', s2[i] - 'a');
            }
            for(auto& c : baseStr) {
                c = find(c - 'a') + 'a';
            }
            return baseStr;
        }
    };
