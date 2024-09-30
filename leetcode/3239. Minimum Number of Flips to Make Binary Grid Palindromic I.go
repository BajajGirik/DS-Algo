package leetcode

func min(a, b int) int {
    if a > b {
        return b
    }

    return a
}

func rowPalindrome(grid [][]int) (totalFlips int) {
    for row:=0; row<len(grid); row++ {
        flips := 0;

        colStart := 0;
        colEnd := len(grid[0]) - 1;

        for colStart < colEnd {
            if grid[row][colStart] != grid[row][colEnd]  {
                flips++;
            }
            colStart++;
            colEnd--;
        }

        totalFlips += flips;
    }

    return totalFlips;
}

func colPalindrome(grid [][]int) (totalFlips int) {
    for col:=0; col<len(grid[0]); col++ {
        flips := 0;

        rowStart := 0;
        rowEnd := len(grid) - 1;

        for rowStart < rowEnd {
            if grid[rowStart][col] != grid[rowEnd][col] {
                flips++;
            }
            rowStart++;
            rowEnd--;
        }

        totalFlips += flips;
    }

    return totalFlips;
}

func minFlips(grid [][]int) int {
    return min(
        rowPalindrome(grid),
        colPalindrome(grid),
    );
}
