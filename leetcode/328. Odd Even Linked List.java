class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return head;
        }

        ListNode lastOddNode = head;
        ListNode lastEvenNode = head.next;
        ListNode curr = lastEvenNode.next;

        while(curr != null && curr.next != null) {
            ListNode odd = curr;
            ListNode even = curr.next;

            odd.next = lastOddNode.next;
            lastOddNode.next = odd;
            lastOddNode = odd;

            lastEvenNode.next = even;
            lastEvenNode = even;
            curr = even.next;
        }

        if (curr != null) {
            curr.next = lastOddNode.next;
            lastOddNode.next = curr;
        }

        lastEvenNode.next = null;

        return head;
    }
}
