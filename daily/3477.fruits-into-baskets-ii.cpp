#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size();
            Tree tree(n);
            for(int i = 0;i < n;i++) {
                tree.update(i, baskets[i]);
            }
            int ans = 0;
            for(int i = 0;i < n;i++) {
                if(tree.query(0, n) < fruits[i]) {
                    ans++;
                } else {
                    int l = 0, r = n;
                    while(l + 1 < r) {
                        int mid = (l + r) >> 1;
                        if(tree.query(0, mid) < fruits[i]) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                    tree.update(l, 0);
                }
            }
            return ans;
        }
    };
