#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree
{
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s;
    int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val)
    {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e)
    { // query [ b , e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2)
        {
            if (b % 2)
                ra = f(ra, s[b++]);
            if (e % 2)
                rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
        {
            pos[nums1[i]] = i;
        }
        for (auto &x : nums2)
        {
            x = pos[x];
            cout << x << " ";
        }
        cout << endl;

        Tree left(n), right(n);
        left.update(nums2[0], 1);
        for (int i = 1; i < n; i++)
        {
            right.update(nums2[i], 1);
        }
        ll ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            right.update(nums2[i], -1);
            ans += left.query(0, nums2[i]) * right.query(nums2[i] + 1, n);
            left.update(nums2[i], 1);
        }
        return ans;
    }
};
