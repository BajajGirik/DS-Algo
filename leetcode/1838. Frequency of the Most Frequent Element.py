from typing import List

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()

        l, r = 0, 0
        window_sum = 0
        max_elements = 0

        while l <= r and r < len(nums):
            new_sum = window_sum + nums[r]
            temp = nums[r] * (r - l + 1)

            if temp - new_sum > k:
                window_sum -= nums[l]
                l += 1
                continue
            
            window_sum = new_sum
            max_elements = max(max_elements, r - l + 1)
            r += 1
        
        return max_elements
