package leetcode

func longestOnes(nums []int, k int) int {
    count := 0;
    zeros := 0;
    left := 0
    right := 0

    for right < len(nums) {
        if nums[right] == 1 {
            count = max(count, right-left+1);
            right++;
            continue;
        }

        zeros++;
        if zeros <= k {
            count = max(count, right-left+1);
            right++;
        } else {
            for nums[left] != 0 {
                left++;
            }
            left++;
            zeros-=2;
        }
    }

    return count;
}

func max(a, b int) int {
    if a > b {
        return a;
    }

    return b;
}
