package leetcode;
func canCompleteCircuit(gas []int, cost []int) int {
  sum := 0;
  startIndex := -1;

  for i := 0; i < len(gas); i++ {
    _i := i % len(gas);

    diff := gas[_i] - cost[_i]

    if sum < 0 && diff > 0 {
      sum = diff;
      startIndex = _i;
      continue;
    }
    
    if sum < 0 {
      continue;
    }

    sum += diff;

    if sum >=0 && _i == startIndex {
      return _i;
    }


    if startIndex  == -1 {
      startIndex = 0;
    }
  }

  return -1;
}

// [2,3,4]
// [3,4,3]


// [1,2,3,4,5]
// [3,4,5,1,2]

// [5,1,2,3,4]
// [4,4,1,5,1]

// 9, -8, 2, -4, 2
