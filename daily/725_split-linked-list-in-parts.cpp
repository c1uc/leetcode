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

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int n = 0;
        for(auto* cur = head;cur;cur = cur->next) {
            n++;
        }
        int rest = n % k;
        int len = n / k;

        for(int idx = 0;idx < k;idx++) {
            ans[idx] = head;
            int cur_len = len + (rest-- > 0);
            for(int i = 0;i < cur_len - 1;i++) {
                head = head->next;
            }
            if(!head) {
                break;
            }
            auto* tmp = head->next;
            head->next = nullptr;
            head = tmp;
        }
        return ans;
    }
};


signed main() {_

    return 0;
}
