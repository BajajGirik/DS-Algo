package leetcode;

import "math"

func maxSumDivThree(nums []int) int {
    min1Remainders := make([]int, 0, 2);
    min2Remainders := make([]int, 0, 2);
    
    total := 0;

    for i:=0; i<len(nums); i++ {
        total += nums[i];
        rem := nums[i] % 3;
        if rem == 1 {
            if (len(min1Remainders) == 0) {
                min1Remainders = append(min1Remainders, nums[i]);
                continue;
            }

            if (len(min1Remainders) == 1) {
                min1Remainders = append(min1Remainders, nums[i]);
            }

            if min1Remainders[0] >= nums[i] {
                min1Remainders[1] = min1Remainders[0];
                min1Remainders[0] = nums[i];
            } else if min1Remainders[1] > nums[i] {
                min1Remainders[1] = nums[i];
            }
        } else if rem == 2 {
            if (len(min2Remainders) == 0) {
                min2Remainders = append(min2Remainders, nums[i]);
                continue;
            }

            if (len(min2Remainders) == 1) {
                min2Remainders = append(min2Remainders, nums[i]);
            }

            if min2Remainders[0] >= nums[i] {
                min2Remainders[1] = min2Remainders[0];
                min2Remainders[0] = nums[i];
            } else if min2Remainders[1] > nums[i] {
                min2Remainders[1] = nums[i];
            }
        }
    }

    rem := total % 3;
    
    if rem == 1 {
        sub := math.MaxInt;
        if (len(min1Remainders) >= 1) {
            sub = min1Remainders[0];
        }
        if (len(min2Remainders) >= 2) {
            sub = min(sub, min2Remainders[0] + min2Remainders[1]);
        }

        total -= sub;
    } else if rem == 2 {
        sub := math.MaxInt;
        if (len(min2Remainders) >= 1) {
            sub = min2Remainders[0];
        }
        if (len(min1Remainders) >= 2) {
            sub = min(sub, min1Remainders[0] + min1Remainders[1]);
        }

        total -= sub;
    }

    return total;
}

func min(a, b int) int {
    if (a > b) {
        return b;
    }
    return a;
}
