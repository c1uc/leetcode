class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto first = letters[0];
        ranges::sort(letters);
        auto p = upper_bound(letters.begin(), letters.end(), target);
        return p != letters.end() ? *p : first;
    }
};
