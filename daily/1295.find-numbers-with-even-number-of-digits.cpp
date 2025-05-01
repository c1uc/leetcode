#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

auto digit_count = [](int n){
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int n){
            return digit_count(n) % 2 == 0;
        });
    }
};
