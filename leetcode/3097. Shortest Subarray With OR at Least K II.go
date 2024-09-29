package leetcode

// import "fmt"

func getBinaryRepresentation(num int) (bits [32]int) {
	for i := 0; i < 32; i++ {
		bits[i] = num & 1
		num = num >> 1
	}

	return bits
}

func isMatch(a [32]int, num int) bool {
	b := getBinaryRepresentation(num)
	for i := 31; i >= 0; i-- {
		if a[i] > 0 && b[i] <= 0 {
			return true
		}

		if b[i] > 0 && a[i] <= 0 {
			return false
		}
	}
	return true
}

func appendBits(a [32]int, num int) (bits [32]int) {
	numBits := getBinaryRepresentation(num)

	for i := 0; i < 32; i++ {
		bits[i] = a[i] + numBits[i]
	}

	return bits
}

func removeBits(a [32]int, num int) (bits [32]int) {
	numBits := getBinaryRepresentation(num)

	for i := 0; i < 32; i++ {
		bits[i] = a[i] - numBits[i]
	}

	return bits
}

func minimumSubarrayLength(nums []int, k int) int {
	result := [32]int{}
	minLength, j := -1, 0

	for i := 0; i < len(nums); i++ {
		found := false

		for ; j < len(nums); j++ {
			result = appendBits(result, nums[j])
			if isMatch(result, k) {
				found = true
				break
			}
		}

		if !found {
			break
		}

		// fmt.Println("*****************")
		// fmt.Println("i: ", i)
		// fmt.Println("j: ", j)
		// fmt.Println("k: ", getBinaryRepresentation(k))
		// fmt.Println("r: ", result)

		for ; i < j; i++ {
			tempResult := removeBits(result, nums[i])

			if !isMatch(tempResult, k) {
				break
			}

			result = tempResult
		}

		// fmt.Println(">>>>>>>>>>>>>>>>>")
		// fmt.Println("i: ", i)
		// fmt.Println("j: ", j)
		// fmt.Println("result: ", result)
		currLength := j - i + 1
		if minLength == -1 || minLength > currLength {
			minLength = currLength
		}

		if minLength == 0 {
			break
		}

		result = removeBits(result, nums[i])
		// fmt.Println("finalResult: ", result)
		// fmt.Println("*****************")
		j++
	}

	return minLength
}
