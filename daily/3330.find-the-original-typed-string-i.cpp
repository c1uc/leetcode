#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int possibleStringCount(string word) {
        return ranges::fold_left(views::iota(1, (int)word.size()), 0, [&](int acc, int i) {
            return acc + (i > 0 && word[i] == word[i - 1]? 1 : 0);
        }) + 1;
    }
};
