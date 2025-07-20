package leetcode;

import "slices";

func napSack(coins []int, target int, index int) bool {
    if target == 0 {
        return true;
    }

    if target < 0 || index >= len(coins) {
        return false;
    }

    return napSack(coins, target - coins[index], index + 1) || napSack(coins, target, index + 1);
}

func getMaximumConsecutiveUnoptimized(coins []int) int {
    sum := 0;

    for i:=0; i<len(coins); i++ {
        sum += coins[i];
    }

    consecutive := 1;

    for i:=1; i<=sum; i++ {
        if i == sum || napSack(coins, i, 0) {
            consecutive += 1;
        } else {
            break;
        }
    }

    return consecutive;
}

func getMaximumConsecutive(coins []int) int {
    slices.Sort(coins);

    sums := 0;

    for i:=0; i<len(coins); i++ {
        if sums < coins[i] - 1 {
            break;
        }

        sums += coins[i];
    }

    return sums + 1;
}

func max(a, b int) int {
    if a > b {
        return a;
    }

    return b;
}

/**
[1,4,10,3,1]

[1,1,3,4,10]


[3,4,5,6,7,8]


*/
