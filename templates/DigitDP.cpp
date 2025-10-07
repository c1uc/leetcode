/*
Digit DP Template Usage Guide

This template provides a flexible framework for solving digit dynamic programming (Digit DP) problems, especially those involving counting numbers with certain digit constraints in a given range.

Key Concepts:
- The DP state is defined by the current digit position `i`, a bitmask `mask` representing used digits, and two booleans: `is_limit` (whether the current prefix is limited by the upper bound) and `is_num` (whether a number has started).
- The DP table `dp` is typically sized as `dp[pos][mask]`, where `pos` is the digit index and `mask` encodes used digits.
- The recursive function `dfs` explores all possible digits at each position, handling leading zeros and upper bound constraints.

How to Use:
1. Convert the target number to a string: `s = to_string(n);`
2. Initialize the DP table: `dp.assign(s.size(), vector<int>(1 << 10, -1));`
3. Call the DP: `int ans = dfs(0, 0, true, false);`
   - `0`: starting at the first digit
   - `0`: no digits used yet
   - `true`: the number is limited by the upper bound initially
   - `false`: no number has started (to handle leading zeros)
4. For range queries (e.g., count in [L, R]), call the DP for both bounds and subtract as needed.

Parameters:
- `i`: Current digit index in the string representation of the number.
- `mask`: Bitmask of used digits (for problems like "no repeated digits").
- `is_limit`: If true, the current prefix matches the upper bound; restricts the next digit.
- `is_num`: If true, a number has started (to skip leading zeros).

Customization:
- Modify the mask and transitions for different digit constraints (e.g., no adjacent duplicates, sum of digits, etc.).
- Adjust the base case and DP dimensions as needed for the specific problem.

Example (Count numbers with unique digits in [0, n]):
    string s = to_string(n);
    dp.assign(s.size(), vector<int>(1 << 10, -1));
    int ans = dfs(0, 0, true, false);

Note:
- The template assumes at most 10 digits (decimal). For other bases, adjust the mask size.
- The lambda `dfs` uses C++20's "this auto&&" for recursion. For older standards, use a regular function.

*/


#include <bits/stdc++.h>
using namespace std;

string s;
vector<vector<int>> dp(s.size(), vector<int>(1 << 10, -1));

auto dfs = [&](this auto&& dfs, int i, int mask, bool is_limit, bool is_num) -> int {
    if(i == s.size()) return is_num;
    if(!is_limit && dp[i][mask] != -1) return dp[i][mask];
    int res = 0;

    if(!is_num) res += dfs(i + 1, mask, false, false);

    int low = is_num ? 0 : 1;
    int high = is_limit ? s[i] - '0' : 9;

    for(int d = low; d <= high; d++) {
        if(mask & (1 << d)) continue;
        res += dfs(i + 1, mask | (1 << d), is_limit && d == high, true);
    }
    return is_limit ? res : dp[i][mask] = res;
};