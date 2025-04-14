#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT
{
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif)
    { // a[pos]+=dif
        for (; pos < sz(s); pos |= pos + 1)
            s[pos] += dif;
    }
    ll query(int pos)
    { // sumof values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1)
            res += s[pos - 1];
        return res;
    }
    int lower_bound(ll sum)
    { // minpos st sumof [0, pos]>=sum
        // Returns n if no sum is>=sum, or= 1 if empty sum is.
        if (sum <= 0)
            return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1)
        {
            if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
                pos += pw, sum -= s[pos - 1];
        }
        return pos;
    }
};

class Solution
{
public:
    vector<int> treeQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        map<pair<int, int>, int> edgeToIndex;
        vector<int> edgeWeights(edges.size());

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
            edgeToIndex[{min(u, v), max(u, v)}] = i;
            edgeWeights[i] = w;
        }

        vector<int> in(n + 1), out(n + 1);
        vector<int> tour;
        int time = 0;

        auto dfs = [&](this auto &&dfs, int u, int p) -> void
        {
            in[u] = ++time;
            tour.push_back(u);
            for (auto [v, idx] : adj[u])
            {
                if (v == p)
                    continue;
                dfs(v, u);
            }
            out[u] = time;
        };
        dfs(1, -1);

        FT ft(time + 2);
        vector<int> depth(n + 1, 0);
        vector<ll> dist(n + 1, 0);

        auto init = [&](this auto &&init, int u, int p, ll current_dist) -> void
        {
            dist[u] = current_dist;
            for (auto [v, idx] : adj[u])
            {
                if (v == p)
                    continue;
                depth[v] = depth[u] + 1;
                init(v, u, current_dist + edgeWeights[idx]);
            }
        };
        init(1, -1, 0);

        for (int i = 1; i <= n; i++)
        {
            ft.update(in[i], dist[i]);
            ft.update(in[i] + 1, -dist[i]);
        }

        vector<int> answer;
        for (auto &query : queries)
        {
            if (query[0] == 1)
            {
                int u = query[1], v = query[2], w = query[3];
                int idx = edgeToIndex[{min(u, v), max(u, v)}];
                int oldWeight = edgeWeights[idx];
                int delta = w - oldWeight;
                edgeWeights[idx] = w;

                int deeper = (depth[u] > depth[v]) ? u : v;

                ft.update(in[deeper], delta);
                ft.update(out[deeper] + 1, -delta);
            }
            else
            {
                int x = query[1];
                answer.push_back(ft.query(in[x] + 1));
            }
        }

        return answer;
    }
};