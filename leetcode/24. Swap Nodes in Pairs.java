/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
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

    public ListNode swapPairs(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode currNode = head;
        ListNode prevNode = null;

        if (head.next != null) {
            head = head.next;
        }

        while (currNode != null && currNode.next != null) {
            ListNode nextNode = currNode.next;

            currNode.next = nextNode.next;
            nextNode.next = currNode;

            if (prevNode != null) {
                prevNode.next = nextNode;
            }

            prevNode = currNode;
            currNode = currNode.next;
        }

        return head;
    }
}
