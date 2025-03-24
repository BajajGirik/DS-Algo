class ListNode {
   val: number
   next: ListNode | null
   constructor(val?: number, next?: ListNode | null) {
       this.val = (val===undefined ? 0 : val)
       this.next = (next===undefined ? null : next)
   }
}
 

function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (!head || !head.next || k === 0) {
        return head;
    }

    let curr: ListNode | null = head;

    let totalNodes = 0;

    while (curr) {
        curr = curr.next;
        totalNodes++;
    }

    k = k % totalNodes;

    if (k === 0) {
        return head;
    }

    curr = head;
    for (let i=0; i < totalNodes - k - 1; i++) {
        curr = curr!.next;
    }

    let next = curr!.next;
    curr!.next = null;

    const newHead = next;
    
    while (next!.next) {
        next = next!.next;
    }

    next!.next = head;

    return newHead;
};
