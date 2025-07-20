package leetcode;

/**
 * Definition for a binary tree node.
 */

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func getGoodNodeCount(root *TreeNode, maxValInPath int) int {
    if root == nil {
        return 0;
    }

    val := root.Val

    _maxValInPath := max(val, maxValInPath);


    goodNodeCount := getGoodNodeCount(root.Left, _maxValInPath) + getGoodNodeCount(root.Right, _maxValInPath)

    if val >= maxValInPath {
        goodNodeCount += 1
    }

    return goodNodeCount;
}

func goodNodes(root *TreeNode) int {
    return getGoodNodeCount(root, root.Val);
}

func max(a, b int) int {
    if a > b {
        return a
    }

    return b
}
