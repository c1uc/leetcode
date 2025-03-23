/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, set<int>> idx;
    unordered_map<int, int> val;

    NumberContainers() {
        idx.clear();
        val.clear();
    }
    
    void change(int index, int number) {
        if(val.find(index) != val.end()) {
            idx[val[index]].erase(index);
        }
        val[index] = number;
        idx[number].insert(index);
    }
    
    int find(int number) {
        return (idx.find(number) == idx.end() || idx.find(number)->second.empty() ? -1 : *idx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end

