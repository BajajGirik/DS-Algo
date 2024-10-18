package leetcode

import "strconv"

func minPartitions(n string) int {
	maxDigit := 0
	for i := 0; i < len(n); i++ {
		digit, _ := strconv.Atoi(string(n[i]))
		if digit > maxDigit {
			maxDigit = digit
		}
	}

	return maxDigit
}
