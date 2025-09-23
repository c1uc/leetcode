#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<int> v1, v2;
            stringstream ss1(version1), ss2(version2);
            string s;
            while(getline(ss1, s, '.')) v1.push_back(stoi(s));
            while(getline(ss2, s, '.')) v2.push_back(stoi(s));
            int n = max(v1.size(), v2.size());
            for(int i = 0; i < n; i++) {
                int x = i < v1.size() ? v1[i] : 0;
                int y = i < v2.size() ? v2[i] : 0;
                if(x > y) return 1;
                if(x < y) return -1;
            }
            return 0;
        }
    };
