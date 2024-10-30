package leetcode;

/**
 * Definition for a Node.
 */
type Node struct {
    Val int
    Children []*Node
}

func preorderHelper(root *Node, result []int) []int {
    if root == nil {
        return result;
    }

    result = append(result, root.Val);
    for i:=0; i<len(root.Children); i++ {
        result = preorderHelper(root.Children[i], result);
    }

    return result;
}

func preorder(root *Node) []int {
    return preorderHelper(root, []int{});
}
