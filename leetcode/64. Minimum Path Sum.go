package leetcode;

var dp [][]int;

func minDistance(grid [][]int, i, j int) int {
    if i == len(grid)-1 && j == len(grid[0])-1 {
        return grid[i][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    minDist := -1;

    if i+1 < len(grid) {
        minDist = minDistance(grid, i+1, j);
    }

    if j+1 < len(grid[0]) {
        temp := minDistance(grid, i, j+1);
        if minDist == -1 || temp < minDist {
            minDist = temp;
        }
    }

    dp[i][j] = minDist + grid[i][j];
    return dp[i][j];
}


func minPathSum(grid [][]int) int {
    dp = [][]int{};

    for i := 0; i < len(grid); i++ {
        row := []int{};

        for j := 0; j < len(grid[0]); j++ {
            row = append(row, -1);
        }

        dp = append(dp, row);
    }

    return minDistance(grid, 0, 0);    
}
