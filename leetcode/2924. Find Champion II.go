package leetcode;

func findChampion(n int, edges [][]int) int {
  if n == 1 {
    return 0;
  }

  primaries := map[int]bool{};
  secondaries := map[int]bool{};

  for i:=0; i<n; i++ {
    primaries[i] = true;
  }

  for i:=0; i<len(edges); i++ {
    edge := edges[i];

    stronger := edge[0];
    weaker := edge[1];

    secondaries[weaker] = true;

    val, ok := primaries[weaker];
    if ok || val {
      delete(primaries, weaker);
    }

    val, ok = secondaries[stronger];
    if !ok && !val {
      primaries[stronger] = true;
    }
  }

  if len(primaries) == 1 {
    key := 0;

    for k, _ := range primaries {
      key = k;
      break;
    }

    return key;
  }


  return -1;
}
