using ti = tuple<int, int, char, int>;
using pi = pair<int, int>;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hl, string dir) {
        int n = pos.size();
        vector<ti> vec;
        vec.reserve(n);
        for (int i = 0; i < n; i++)
            vec.emplace_back(pos[i], hl[i], dir[i], i);
        ranges::sort(vec);

        stack<pi> st;
        vector<pi> res;

        for (auto& [_, h, d, idx] : vec) {
            if (d == 'R') {
                st.push({idx, h});
            } else {
                int hp = h;
                while (!st.empty() && hp) {
                    auto [ii, hh] = st.top();
                    st.pop();
                    if (hh > hp) {
                        st.push({ii, hh - 1});
                        hp = 0;
                    } else if (hp > hh) {
                        hp--;
                    } else {
                        hp = 0;
                    }
                }
                if (hp > 0) res.emplace_back(idx, hp);
            }
        }

        while (!st.empty()) {
            res.emplace_back(st.top());
            st.pop();
        }

        ranges::sort(res);
        return res | views::transform([](auto p) { return p.second; })
                    | ranges::to<vector<int>>();
    }
};
