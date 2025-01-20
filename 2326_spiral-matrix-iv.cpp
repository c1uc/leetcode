//
// Created by duck on 2024/9/10.
//
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        auto ans = vector<vector<int>>(m, vector(n, -1));
        auto dir = vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto cur = pair{0, 0};
        int idx = 0;
        while(head) {
            ans[cur.first][cur.second] = head->val;
            head = head->next;

            auto nxt = cur + dir[idx];
            if(nxt.first < 0 || nxt.first >= m || nxt.second < 0 || nxt.second >= n || ans[nxt.first][nxt.second] != -1) {
                idx = (idx + 1) % 4;
                nxt = cur + dir[idx];
            }
            cur = nxt;
        }
        return ans;
    }
};


signed main() {_

    return 0;
}
