package leetcode

/* import (
  "fmt"
  "sort"
) */

/* func min(a, b int) int {
  if (a > b) {
    return b;
  }

  return a;
} */

func subsetsWithDup(nums []int) [][]int {
  freqMap := make(map[int]int);

  for i := 0; i < len(nums); i++ {
    freqMap[nums[i]]++;
  }

  results := [][]int{};
  results = append(results, []int{});

  /* keys := make([]int, len(freqMap));

  keyIndex := 0;
  for k, _ := range freqMap {
    keys[keyIndex] = k;
    keyIndex++;
  }

  fmt.Println(keys);

  sort.Sort(sort.IntSlice(keys));

  fmt.Println(keys); */

  for k, v := range freqMap {
    originalLen := len(results);
    for i:=0; i< originalLen; i++ {
      temp := make([]int, len(results[i]));
      copy(temp, results[i]);
      results = append(results, append(temp, k));
    }

    for i:=1; i<v; i++ {
      for j:=0; j < originalLen; j++ {
        temp := make([]int, len(results[j + i * originalLen]));
        copy(temp, results[j + i * originalLen]);
        results = append(results, append(temp, k));
      }
    }
  }

  /* sort.Slice(results, func(i, j int) bool {
    r1 := results[i];
    r2 := results[j];

    for index:=0; index < min(len(r1), len(r2)); index++ {
      if (r1[index] != r2[index]) {
        return r1[index] < r2[index];
      }
    }

    return len(r1) < len(r2);
  }); */

  return results;
}

/**

1
1, 2, {1,2}
1, 2, {1,2}, {2,2}, {1,2,2}, 

*/

