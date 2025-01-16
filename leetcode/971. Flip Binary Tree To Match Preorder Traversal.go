package leetcode;

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var hops []int;
var index int;

func helper(root *TreeNode, voyage []int) bool {
    // if root != nil {
    //     fmt.Println("Root Value: ", root.Val);
    // } else {
    //     fmt.Println("Root is null")
    // }
    // fmt.Println("Index: ", index);
    
    if index >= len(voyage) || root == nil {
        return true;
    }

    if root.Val != voyage[index] {
        return false;
    }

    index++;

    if index == len(voyage) - 1  || (root.Right == nil && root.Left == nil) {
        return true;
    }

    if root.Left != nil && root.Left.Val == voyage[index] {
        // fmt.Println("Left Side sweep");
        if !helper(root.Left, voyage) {
            // fmt.Println("Left Side sweep failed");
            return false;
        }

        return helper(root.Right, voyage);
    } else if root.Right != nil && root.Right.Val == voyage[index] {
        if root.Left != nil {
            hops = append(hops, root.Val);
        }
        // fmt.Println("Right Side sweep");
        if !helper(root.Right, voyage) {
            // fmt.Println("Right side sweep failed");
            return false;
        }

        return helper(root.Left, voyage);
    } else {
        return false;
    }
}


func flipMatchVoyage(root *TreeNode, voyage []int) []int {
    hops = []int{};
    index = 0;
    canFlip := helper(root, voyage);

    if canFlip {
        return hops;
    }
    
    return []int{-1};
}
