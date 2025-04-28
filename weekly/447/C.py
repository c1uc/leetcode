from itertools import permutations
from typing import List

class Solution:
    def concatenatedDivisibility(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        lengths = [len(str(x)) for x in nums]
        mods = [x % k for x in nums]
        pow10 = [pow(10, lengths[i], k) for i in range(n)]


        full_mask = (1 << n) - 1
        dp = [[False] * k for _ in range(1 << n)]

        for r in range(k):
            dp[full_mask][r] = (r == 0)

        for mask in range(full_mask - 1, -1, -1):
            for r in range(k):
                for j in range(n):
                    if not (mask & (1 << j)):
                        new_r = (r * pow10[j] + mods[j]) % k
                        if dp[mask | (1 << j)][new_r]:
                            dp[mask][r] = True
                            break

        if not dp[0][0]:
            return []

        result = []
        mask = 0
        r = 0
        sorted_pairs = sorted((nums[i], i) for i in range(n))

        for _ in range(n):
            for value, j in sorted_pairs:
                if not (mask & (1 << j)):
                    new_r = (r * pow10[j] + mods[j]) % k
                    if dp[mask | (1 << j)][new_r]:
                        result.append(value)
                        mask |= (1 << j)
                        r = new_r
                        break

        return result