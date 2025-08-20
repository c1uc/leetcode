#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class Solution {
    public:
        string answerString(string word, int numFriends) {
            int n = word.size();
            int i = 0, j = 1, k = 0;
            while(j + k < n) {
                if(word[i + k] == word[j + k]) {
                    k++;
                } else if(word[i + k] < word[j + k]) {
                    i = j;
                    j = max(j + 1, i + k + 1);
                    k = 0;
                } else {
                    j += k + 1;
                    k = 0;
                }
            }
            return word.substr(i, min(n - i, n - numFriends + 1));
        }
    };
