class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<long long> high, low;
        long long ans = LLONG_MAX, low_sum = 0;
        for(auto [i, x]: nums | views::enumerate | views::drop(1)) {
            if(low.empty() || x < *low.rbegin()) {
                low.insert(x);
                low_sum += x;
            } else high.insert(x);

            int l = i - dist - 1;
            if(l >= 1) {
                if(high.count(nums[l])) {
                    high.erase(high.find(nums[l]));
                } else {
                    low.erase(low.find(nums[l]));
                    low_sum -= nums[l];
                }
            }

            while(low.size() < k - 1 && !high.empty()) {
                auto t = high.begin();

                low.insert(*t);
                low_sum += *t;

                high.erase(t);
            }

            while(low.size() > k - 1) {
                auto t = low.end();
                t--;

                high.insert(*t);

                low_sum -= *t;
                low.erase(t);
            }

            if(low.size() == k - 1) ans = min(ans, low_sum + nums[0]);
        }
        return ans;
    }
};
