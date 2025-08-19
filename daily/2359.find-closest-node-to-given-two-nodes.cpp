#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n = edges.size();
            vector<int> vis1(n, 0), vis2(n, 0);
            int u = node1, v = node2, ans = n;
            while(!vis1[u] || !vis2[v]) {
                vis1[u] = 1;
                vis2[v] = 1;

                if(vis2[u]) ans = u;
                if(vis1[v]) ans = min(ans, v);

                if(ans < n) return ans;

                if(edges[u] != -1) u = edges[u];
                if(edges[v] != -1) v = edges[v];
            }
            return -1;
        }
    };
