package leetcode

import "sort"

func minOperationsToMakeMedianK(nums []int, k int) int64 {
	sort.Slice(nums, func(a, b int) bool {
		return nums[a] < nums[b]
	})

	// fmt.Println(nums)
	medianIndex := len(nums) / 2

	// fmt.Println(medianIndex, nums[medianIndex])

	count := int64(0)
	if k > nums[medianIndex] {
		for i := medianIndex; i < len(nums); i++ {
			if k-nums[i] <= 0 {
				break
			}
			count += int64(k - nums[i])
		}
	} else {
		for i := medianIndex; i >= 0; i-- {
			if nums[i]-k <= 0 {
				break
			}
			count += int64(nums[i] - k)
		}
	}

	return count
}
