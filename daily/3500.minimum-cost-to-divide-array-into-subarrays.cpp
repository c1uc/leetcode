/*
 * @lc app=leetcode id=3500 lang=cpp
 *
 * [3500] Minimum Cost to Divide Array Into Subarrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Line
{
    mutable ll k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>>
{
    // ( for doubles , use inf = 1/.0, div(a, b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b)
    { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y)
    {
        if (y == end())
            return x->p = inf, 0;
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m)
    {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x)
    {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

class Solution
{
public:
    long long minimumCost(vector<int> &nums, vector<int> &cost, int k)
    {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
            cost[i] += cost[i - 1];
        }
        nums.insert(nums.begin(), 0);
        cost.insert(cost.begin(), 0);
        LineContainer hull;
        for (int i = n - 1; i >= 0; i--)
        {
            hull.add(nums[i + 1], -(dp[i + 1] + nums[i + 1] * cost[i + 1]));
            dp[i] = k * (cost[n] - cost[i]) - hull.query(cost[i]);
        }
        return dp[0];
    }
};
// @lc code=end
