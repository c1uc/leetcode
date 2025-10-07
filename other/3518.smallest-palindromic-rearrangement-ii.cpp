#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string smallestPalindrome(string s, int k) {
            int n = s.size();
            int m = n >> 1;
            vector<int> cnt(26, 0);
            for(int i = 0;i < m;i++) {
                cnt[s[i] - 'a']++;
            }

            auto comb = [&](int N, int K) -> int {
                int c = min(K, N - K);
                long long res = 1;
                for(int i = 0;i < c;i++) {
                    res *= (N - i);
                    res /= (i + 1);
                    if(res >= k) return k;
                }
                return (int)res;
            };

            auto perm = [&](int size) {
                long long res = 1;
                for(int i = 0;i < 26;i++) {
                    if(cnt[i] == 0) continue;
                    res *= comb(size, cnt[i]);
                    size -= cnt[i];
                    if(res >= k) return k;
                }
                return (int)res;
            };

            if(perm(m) < k) return "";

            string ans;

            for(int i = 0;i < m;i++) {
                for(int c = 0;c < 26;c++) {
                    if(cnt[c] == 0) continue;
                    cnt[c]--;
                    int p = perm(m - i - 1);
                    if(p >= k) {
                        ans += 'a' + c;
                        break;
                    }
                    cnt[c]++;
                    k -= p;
                }
            }
            auto rev = ans;
            reverse(rev.begin(), rev.end());
            if(n & 1) {
                ans += s[m];
            }
            ans += rev;
            return ans;
        }
    };
