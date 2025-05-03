#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        for(int i = 1;i <= 6;i++)
        {
            int cnt1 = 0,cnt2 = 0;
            for(int j = 0;j < n;j++)
            {
                if(tops[j] == i) cnt1++;
                if(bottoms[j] == i) cnt2++;
                if(tops[j] != i && bottoms[j] != i) break;
            }
            if(cnt1 + cnt2 >= n)
            {
                return n - max(cnt1,cnt2);
            }
        }
        return -1;
    }
};
