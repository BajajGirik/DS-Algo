package leetcode;

var memo []int;

func helper(cost []int, index int) int {
    if index >= len(cost) - 2 {
        return cost[index];
    }

    if memo[index] != -1 {
        return memo[index];
    }

    memo[index] = min(helper(cost, index + 1), helper(cost, index + 2)) + cost[index];

    return memo[index];
}

func minCostClimbingStairs(cost []int) int {
    memo = []int{};

    for i:=0; i<len(cost); i++ {
        memo = append(memo, -1);
    }

    return min(helper(cost, 0), helper(cost, 1))
}

func min(a, b int) int {
    if a < b {
        return a;
    }

    return b;
}
