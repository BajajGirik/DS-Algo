package leetcode;

var memo [][]int;

func helper(m, n int) int {
    if m == 0 || n == 0 {
        return 1;
    }

    if memo[m][n] != -1 {
        return memo[m][n];
    }

    memo[m][n] = helper(m-1, n) + helper(m, n-1);

    return memo[m][n];
}

func uniquePaths(m int, n int) int {
    memo = [][]int{};

    for i:=0; i<m; i++ {
        row := []int{};

        for j:=0; j<n; j++ {
            row = append(row, -1);
        }

        memo = append(memo, row)
    }

    return helper(m-1, n-1);
}
