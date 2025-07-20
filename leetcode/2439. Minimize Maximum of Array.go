package leetcode;

import "math"

func backtrack(nums []int, index int) {
    sum := nums[index];
    stopIndex := index;

    for i := index - 1; i >= 0; i-- {
        totalElements := index - stopIndex + 1;
        val := sum / totalElements;
        remainder := sum % totalElements;

        if remainder > 0 {
            val += 1;
        }

        if nums[i] > val {
            break;
        }

        sum += nums[i];
        stopIndex = i;
    }

    totalElements := index - stopIndex + 1;
    val := sum / totalElements;
    remainder := sum % totalElements;

    for i:=stopIndex; i<=index; i++ {
        if (remainder != 0) {
            nums[i] = val + 1;
            remainder -= 1;
        } else {
            nums[i] = val;
        }
    }
}

func minimizeArrayValueUnoptimized(nums []int) int {
    for i:=1; i<len(nums); i++ {
        backtrack(nums, i);
    }


    maximum := nums[0];
    for i:=1; i<len(nums); i++ {
        if nums[i] > maximum {
            maximum = nums[i];
        }
    }

    return maximum
}

func minimizeArrayValue(nums []int) int {
    result := 0;
    sum := 0;

    for i:=0; i<len(nums); i++ {
        sum += nums[i];
        val := int(math.Ceil(float64(sum) / float64(i + 1)));

        if val > result {
            result = val;
        }
    }

    return result;
}

/**
3,3,3,3,3,4

3,1,1,7

5 + 7 = 12 / 4
*/
