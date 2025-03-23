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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto* new_head = new ListNode(head->val);
        auto* cur = new_head;
        while(head->next) {
            int g = gcd(head->val, head->next->val);
            cur->next = new ListNode(g);
            cur = cur->next;
            cur->next = new ListNode(head->next->val);

            head = head->next;
            cur = cur->next;
        }
        return new_head;
    }
};


signed main() {_
    Solution s;
    // test case: 18, 6, 10, 3
    auto* head = new ListNode(18);
    auto* new_head = s.insertGreatestCommonDivisors(head);
    while(new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
