package leetcode;

var memo map[int]int;

func helper(n int) int {
    val, ok := memo[n]

    if ok {
        return val;
    }

    if n == 0 {
        return 1;
    }

    if n < 0 {
        return 0;
    }

    memo[n] = helper(n - 1) + helper(n - 2);

    return memo[n];
}

func climbStairs(n int) int {
    memo = map[int]int{};
    result := helper(n);
    memo = nil;

    return result;
}
