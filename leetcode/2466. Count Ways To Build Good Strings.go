package leetcode;

var combinationCount map[int]int;

func count(low, high, zero, one, currCount int) int {
    if currCount > high {
        return 0;
    }

    val, ok := combinationCount[currCount];
    if ok {
        return val;
    }

    totalCount := 0;
    if currCount >= low {
        // fmt.Println(combination);
        totalCount = 1;
    }

    totalCount = (totalCount + count(low, high, zero, one, currCount + zero)) % 1000000007;
    totalCount = (totalCount + count(low, high, zero, one, currCount + one)) % 1000000007;

    combinationCount[currCount] = totalCount;
    return combinationCount[currCount];
}

func countGoodStrings(low int, high int, zero int, one int) int {
    combinationCount = map[int]int{};
    return count(low, high, zero, one, 0);
}
