package leetcode

type TreeNode struct {
   Val int
   Left *TreeNode
   Right *TreeNode
}

var moves int = 0;

func countMoves(root *TreeNode) (pendingCoins, carriedCoins int) {
    if (root.Left != nil) {
        a, b := countMoves(root.Left);
        pendingCoins += a;
        carriedCoins += b;
    }

    if (root.Right != nil) {
        a, b := countMoves(root.Right);
        pendingCoins += a;
        carriedCoins += b;
    }

    if (root.Val + carriedCoins - 1 < pendingCoins) {
        moves += pendingCoins - root.Val - carriedCoins + 1;
        return pendingCoins - root.Val - carriedCoins + 1, 0;
    }

    moves += carriedCoins + root.Val - pendingCoins - 1;
    return 0, carriedCoins + root.Val - pendingCoins - 1;
}

func distributeCoins(root *TreeNode) int {
    moves = 0;
    countMoves(root);
    return moves;
}
