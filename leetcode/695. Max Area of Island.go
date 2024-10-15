package leetcode;

func findArea(grid [][]int, visited [][]bool, i int, j int) (area int) {
    if visited[i][j] || grid[i][j] == 0 {
        return 0;
    }

    visited[i][j] = true;
    area = 1;

    if i - 1 >= 0 {
        area += findArea(grid, visited, i-1, j);
    }
    if i + 1 < len(grid) {
        area += findArea(grid, visited, i+1, j);
    }
    if j - 1 >= 0 {
        area += findArea(grid, visited, i, j-1);
    }
    if j + 1 < len(grid[0]) {
        area += findArea(grid, visited, i, j+1);
    }

    return area;
}

func maxAreaOfIsland(grid [][]int) int {
    visited := make([][]bool, len(grid));
    for i:=0; i<len(grid); i++ {
        visited[i] = make([]bool, len(grid[i]));
    }

    maxArea := 0;

    for i:=0; i<len(grid); i++ {
        for j:=0; j<len(grid[i]); j++ {
            if grid[i][j] == 0 || visited[i][j] {
                continue;
            }

            area := findArea(grid, visited, i, j);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}
