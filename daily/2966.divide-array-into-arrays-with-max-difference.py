from typing import List

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort(); return [] if any(nums[i + 2] - nums[i] > k for i in range(0, len(nums), 3)) else [nums[i:i + 3] for i in range(0, len(nums), 3)]
        