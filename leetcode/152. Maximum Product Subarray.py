from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max = 1
        curr_min = 1
        res = nums[0]

        for i in range(len(nums) - 1, -1, -1):
            tmp1 = curr_max * nums[i]
            tmp2 = curr_min * nums[i]

            curr_max = max(
                tmp1,
                tmp2,
                nums[i]
            )

            curr_min = min(
                tmp1,
                tmp2,
                nums[i]
            )

            res = max(curr_max, res)


        return res
