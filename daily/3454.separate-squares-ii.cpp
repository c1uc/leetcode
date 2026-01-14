#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
        vector<int> count;
        vector<int> covered;
        vector<int> xs;
        int n;
    
        void modify(int qleft, int qright, int qval, int left, int right, int pos) {
            if (xs[right + 1] <= qleft || xs[left] >= qright) {
                return;
            }
            if (qleft <= xs[left] && xs[right + 1] <= qright) {
                count[pos] += qval;
            } else {
                int mid = (left + right) / 2;
                modify(qleft, qright, qval, left, mid, pos * 2 + 1);
                modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
            }
    
            if (count[pos] > 0) {
                covered[pos] = xs[right + 1] - xs[left];
            } else {
                if (left == right) {
                    covered[pos] = 0;
                } else {
                    covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
                }
            }
        }
    
    public:
        SegmentTree(vector<int>& xs_) : xs(xs_) {
            n = xs.size() - 1;
            count.resize(4 * n, 0);
            covered.resize(4 * n, 0);
        }
    
        void update(int qleft, int qright, int qval) {
            modify(qleft, qright, qval, 0, n - 1, 0);
        }
    
        int query() { return covered[0]; }
    };


class Solution {
    public:
        double separateSquares(vector<vector<int>>& squares) {
            int n = squares.size();
            set<int> xs;
            unordered_map<int, int> x_idx;
            vector<tuple<int, int, int, int>> events;
            for(int i = 0; i < n; i++) {
                int x = squares[i][0], y = squares[i][1], w = squares[i][2];
                xs.insert(x);
                xs.insert(x + w);
                events.push_back({y, x, x + w, 1});
                events.push_back({y + w, x, x + w, -1});
            }
            sort(events.begin(), events.end());
            vector<int> xs_vec(xs.begin(), xs.end());
            
            vector<int> ys = {get<0>(events[0])};
            vector<long long> areas = {0};
            SegmentTree segtree(xs_vec);
            for(int i = 0; i < events.size(); i++) {
                auto [y, x1, x2, type] = events[i];
                segtree.update(x1, x2, type);
                long long width = segtree.query();
                if(i + 1 < events.size() && get<0>(events[i + 1]) != y) {
                    areas.push_back(areas.back() + width * (get<0>(events[i + 1]) - y));
                    ys.push_back(get<0>(events[i + 1]));
                }
            }

            double half = areas.back() / 2.0;
            int idx = lower_bound(areas.begin(), areas.end(), half) - areas.begin();
            if(areas[idx] == half) return ys[idx];
            else {
                double y1 = ys[idx - 1], y2 = ys[idx];
                double area1 = areas[idx - 1], area2 = areas[idx];
                return y1 + (half - area1) / (area2 - area1) * (y2 - y1);
            }
        }
    };
