/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int totalLength = 0;

        ListNode curr = head;
        /**
         * Previous node of the nth node from the end
         */
        ListNode target = head;

        while (curr != null) {
            if (totalLength > n) {
                target = target.next;
            }

            curr = curr.next;
            totalLength++;
        }

        if (n == totalLength) {
            head = head.next;
            return head;
        }

        if (target == null || target.next == null) {
            return head;
        }

        target.next = target.next.next;
        return head;
    }
}
