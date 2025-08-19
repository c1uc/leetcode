#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
            reverse(board.begin(), board.end());
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) reverse(board[i].begin(), board[i].end());
            }
            vector<int> vis(n * n, 0), dis(n * n, 0);
            queue<int> q;
            q.push(0);
            dis[0] = 0;
            vis[0] = 1;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int i = 1; i <= 6; i++) {
                    int v = u + i, nxt = board[v / n][v % n] - 1;
                    if(v >= n * n) break;
                    if(nxt != -1) v = nxt;
                    if(vis[v]) continue;
                    vis[v] = 1;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
            return dis[n * n - 1];
        }
    };
