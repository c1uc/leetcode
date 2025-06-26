from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = [0] * len(nums)
        for i in [i for i, _ in enumerate(nums) if _ == key]:
            ans[max(0, i - k): min(len(nums), i + k + 1)] = [1] * (min(len(nums), i + k + 1) - max(0, i - k))
        return [i for i, _ in enumerate(ans) if _]