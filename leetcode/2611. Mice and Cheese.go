package leetcode

import "sort"

type DiffernceInfo struct {
	diff  int
	index int
}

func miceAndCheese(reward1 []int, reward2 []int, k int) int {
	diffInfos := []DiffernceInfo{}
  m1Visited := []bool{};

	for i := 0; i < len(reward1); i++ {
		diffInfos = append(diffInfos, DiffernceInfo{diff: reward1[i] - reward2[i], index: i})
    m1Visited = append(m1Visited, false);
	}

	sort.Slice(diffInfos, func(a, b int) bool {
    if (diffInfos[a].diff == diffInfos[b].diff) {
      return diffInfos[a].index > diffInfos[b].index
    }
    return diffInfos[a].diff > diffInfos[b].diff;
  })



  ans := 0;

  for i:=0; i<k; i++ {
    ans += reward1[diffInfos[i].index];
    m1Visited[diffInfos[i].index] = true;
  }

  for i:=0; i<len(reward2); i++ {
    if !m1Visited[i] {
      ans += reward2[i];
    }
  }

	return ans;
}
