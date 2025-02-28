from typing import List

class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        l, r = 1, 1
        max_length = -1
        multiplier = 1

        while r < len(nums):
            if nums[r] == nums[r-1] + multiplier:
                max_length = max(max_length, r-l+2)
                multiplier *= -1
                r += 1
            else:
                if l == r:
                    r += 1

                l = r
                multiplier = 1

        return max_length
