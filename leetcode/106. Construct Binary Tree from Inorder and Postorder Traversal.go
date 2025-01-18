package leetcode;

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var inorderMap map[int]int;
var postorderMap map[int]int;

func helper(inorder []int, postorder []int, rootVal int, lIndex int, rIndex int) *TreeNode {
    // fmt.Println("rootVal:", rootVal);
    node := TreeNode{Val: rootVal};

    rootIndex := inorderMap[rootVal];
    maxIndex := -1;

    for i:=lIndex; i<rootIndex; i++ {
        index := postorderMap[inorder[i]];
        if index > maxIndex {
            maxIndex = index;
        }
    }

    if maxIndex >= 0 {
        // fmt.Println("Left MaxIndex: ", maxIndex);
        // fmt.Println("Left Root: ", postorder[maxIndex]);
        node.Left = helper(inorder, postorder, postorder[maxIndex], lIndex, rootIndex);
    }

    maxIndex = -1;

    for i:=rootIndex + 1; i<rIndex; i++ {
        index := postorderMap[inorder[i]];
        if index > maxIndex {
            maxIndex = index;
        }
    }

    if maxIndex >= 0 {
        // fmt.Println("Right MaxIndex: ", maxIndex);
        // fmt.Println("Right Root: ", postorder[maxIndex]);
        node.Right = helper(inorder, postorder, postorder[maxIndex], rootIndex+1, rIndex);
    }

    return &node;
}



func buildTree(inorder []int, postorder []int) *TreeNode {
    inorderMap = map[int]int{};
    postorderMap = map[int]int{};

    for i:=0; i<len(inorder); i++ {
        inorderMap[inorder[i]] = i;
        postorderMap[postorder[i]] = i;
    }

    // fmt.Println(inorderMap);
    // fmt.Println(postorderMap);

   rootVal := postorder[len(postorder) - 1];
   return helper(inorder, postorder, rootVal, 0, len(postorder));
}
