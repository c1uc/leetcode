/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0;
        auto fast = head, mid = head;
        while(fast != nullptr) {
            fast = fast->next->next;
            mid = mid->next;
        }
        auto cur = mid, prev = (ListNode *)nullptr, nxt = (ListNode *)nullptr;
        while(cur != nullptr) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        while(prev != nullptr) {
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return ans;
    }
};
