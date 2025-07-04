#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        char kthCharacter(long long k, vector<int>& operations) {
            ll mask = ranges::fold_left(operations | views::reverse | views::take(50), 0, [](ll m, int op) {return (m << 1) | op;});
            return 'a' + __builtin_popcountll((k - 1) & mask);
        }
    };
