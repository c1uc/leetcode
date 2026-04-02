class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;
        vector<char> res(len, 0);
        vector<bool> locked(len, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (locked[i + j] && res[i + j] != str2[j]) return "";
                    res[i + j] = str2[j];
                    locked[i + j] = true;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (!locked[i]) res[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool matches = true;
                int lastFree = -1;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        matches = false;
                        break;
                    }
                    if (!locked[i + j]) lastFree = j;
                }
                if (matches) {
                    if (lastFree == -1) return "";
                    res[i + lastFree] = (str2[lastFree] == 'a') ? 'b' : 'a';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool matches = true;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) return "";
            }
        }

        return string(res.begin(), res.end());
    }
};
