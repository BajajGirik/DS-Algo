from typing import List

class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        l, r = 0, 0
        freq = [0] * (len(nums) + 1)

        max_elements = 0

        while r < len(nums):
            freq[nums[r]] += 1

            window_len = r - l + 1
            elements_to_del = window_len - freq[nums[l]]
            
            if elements_to_del > k:
                freq[nums[l]] -= 1
                freq[nums[r]] -= 1
                l += 1
            else:
                max_elements = max(max_elements, freq[nums[l]])
                r += 1

        while l < len(nums):
            window_len = r - l + 1
            elements_to_del = window_len - freq[nums[l]]

            if elements_to_del <= k:
                max_elements = max(max_elements, freq[nums[l]])

            l += 1

        return max_elements
