package leetcode;

func generate(numRows int) [][]int {
    // n -> 1 + 2 + 3 + 4... = n * (n+1) / 2 -> O(n^2)

	dp := [][]int{}
	dp = append(dp, []int{1})

	for i := 1; i < numRows; i++ {
		row := []int{}
		row = append(row, 1)

		prevRow := dp[i-1]
		for j := 1; j < len(prevRow); j++ {
			row = append(row, prevRow[j]+prevRow[j-1])
		}

		row = append(row, 1)
		dp = append(dp, row)
	}

	return dp
}