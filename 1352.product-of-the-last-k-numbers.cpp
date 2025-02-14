/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> nums;
    vector<int> prefix;
    int n;

    ProductOfNumbers() {
        nums.clear();
        prefix.clear();
        n = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            nums.clear();
            prefix.clear();
            n = 0;
            return;
        }
        nums.emplace_back(num);
        if(prefix.empty()) {
            prefix.emplace_back(num);
        } else {
            prefix.emplace_back(prefix.back() * num);
        }
        n++;
    }
    
    int getProduct(int k) {
        return (k > n ? 0 : (k == n ? prefix.back() : prefix.back() / prefix[n - k - 1]));
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

