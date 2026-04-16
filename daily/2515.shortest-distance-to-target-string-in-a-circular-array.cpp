class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
        return ranges::none_of(words, [&](const string& s) { return s == target; })
            ? -1
            : ranges::min(
                words
                | views::enumerate
                | views::filter([&](auto p) { return get<1>(p) == target; })
                | views::transform([&](auto p) {
                      int diff = abs((int)get<0>(p) - st);
                      return min(diff, (int)words.size() - diff);
                  })
              );
    }
};
