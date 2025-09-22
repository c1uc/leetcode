from collections import deque
from typing import List

class Solution:
    def minSplitMerge(self, nums1: List[int], nums2: List[int]) -> int:
        vis = set()
        queue = []

        queue.append((nums1, 0))
        vis.add(tuple(nums1))
        while queue:
            current, ops = queue.pop(0)
            if current == nums2:
                return ops
            for l in range(len(current)):
                for r in range(l, len(current)):
                    subarray = current[l:r+1]
                    remaining = current[:l] + current[r+1:]
                    
                    for pos in range(len(remaining) + 1):
                        new_state = remaining[:pos] + subarray + remaining[pos:]
                        if tuple(new_state) not in vis:
                            if new_state == nums2:
                                return ops + 1

                            vis.add(tuple(new_state))
                            queue.append((new_state, ops + 1))
        return -1

# ©leetcode
