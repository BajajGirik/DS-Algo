package leetcode

type Node struct {
		Val int
		Next *Node
		Random *Node
}

func copyRandomList(head *Node) *Node {
    newHead := &Node{};

    curr := head;
    newPrev := newHead;
    
    oldNodeMap := map[*Node]int{};
    newNodes := []*Node{};

    i := 0
    
    for curr != nil {
        newNode := Node{};
        newNode.Val = curr.Val;
        newPrev.Next = &newNode;

        oldNodeMap[curr] = i;
        newNodes = append(newNodes, &newNode);

        i++;
        curr = curr.Next;
        newPrev = &newNode;
    }

    curr = head;
    newHead = newHead.Next;
    newCurr := newHead;

    for curr != nil {
        if curr.Random != nil {
            index := oldNodeMap[curr.Random];
            newCurr.Random = newNodes[index];
        }

        curr = curr.Next;
        newCurr = newCurr.Next;
    }

    return newHead;
}
