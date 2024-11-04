package leetcode

import "strconv"

var dp map[string]int

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func recurse(s1 string, s2 string, i1 int, i2 int) int {
	i1Str := strconv.Itoa(i1)
	i2Str := strconv.Itoa(i2)
	key := i1Str + "_" + i2Str

	val, ok := dp[key]
	if ok {
		return val
	}

	if i1 >= len(s1) && i2 >= len(s2) {
		return 0
	}

	if i1 >= len(s1) {
		dp[key] = recurse(s1, s2, i1, i2+1) + int(s2[i2])
		return dp[key]
	}

	if i2 >= len(s2) {
		dp[key] = recurse(s1, s2, i1+1, i2) + int(s1[i1])
		return dp[key]
	}

	result := min(
		recurse(s1, s2, i1, i2+1)+int(s2[i2]),
		recurse(s1, s2, i1+1, i2)+int(s1[i1]),
	)

	if s1[i1] == s2[i2] {
		result = min(
			result,
			recurse(s1, s2, i1+1, i2+1),
		)
	}

	dp[key] = result
	return dp[key]
}

func minimumDeleteSum(s1 string, s2 string) int {
	dp = map[string]int{}
	return recurse(s1, s2, 0, 0)
}
