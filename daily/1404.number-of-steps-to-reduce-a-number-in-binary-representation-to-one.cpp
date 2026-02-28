class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool carry = false;
        for(auto c: s | views::drop(1) | views::reverse) {
            if(c == '0') {
                ans += 1 + carry;
            } else {
                ans += 2 - carry;
                carry = true;
            }
        }
        return ans + carry;
    }
};
