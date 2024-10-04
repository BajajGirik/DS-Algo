package leetcode

import "sort"

func minRectanglesToCoverPoints(points [][]int, w int) int {
  count := 0;

  sort.Slice(points, func (i, j int) bool {
    if (points[i][0] != points[j][0]) {
      return points[i][0] < points[j][0];
    }
    return points[i][1] < points[j][1];
  });

  currX := points[0][0];

  for i := 1; i < len(points); i++ {
    x := points[i][0];

    if x - currX <= w {
      continue;
    }

    currX = x;
    count++;
  }

  lastX := points[len(points) - 1][0];
  if (lastX - currX <= w) {
    count++;
  }

  return count;
}
