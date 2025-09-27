package leetcode;

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    dp := [][]int{};
    rLen := len(obstacleGrid);
    cLen := len(obstacleGrid[0]);

    for i:=0; i<rLen; i++ {
        row := []int{};
        for j:=0; j<cLen; j++ {
            row = append(row, 0);
        }
        dp = append(dp, row);
    }

    if obstacleGrid[0][0] == 0 {
        dp[0][0] = 1;
    }

    for i:=1; i<rLen; i++ {
        if obstacleGrid[i][0] == 1 {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }

    for j:=1; j<cLen; j++ {
        if obstacleGrid[0][j] == 1 {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j-1];
        }
    }

    for i:=1; i<rLen; i++ {
        for j:=1; j<cLen; j++ {
            if obstacleGrid[i][j] == 1 {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[rLen-1][cLen-1];
}
