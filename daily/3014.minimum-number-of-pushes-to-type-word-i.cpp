class Solution {
public:
    int minimumPushes(string word) {
        return (int)word.size() + max((int)word.size() - 8, 0) + max((int)word.size() - 16, 0) + max((int)word.size() - 24, 0);
    }
};
