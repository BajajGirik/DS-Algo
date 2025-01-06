package leetcode

func maxArea(height []int) int {
    i := 0;
    j := len(height) - 1;
    area := 0;

    for i < j {
        currArea := min(height[i], height[j]) * (j - i);
        area = max(area, currArea);

        if height[i] > height[j] {
            j--;
        } else {
            i++;
        }
    }

    return area;
}

func max(a, b int) int {
    if a > b {
        return a;
    }

    return b;
}

func min(a, b int) int {
    if a < b {
        return a;
    }

    return b;
}
