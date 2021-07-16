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
class ReverseList {
    public ListNode reverseList(ListNode head) {
        ListNode last = null;
        while(head != null){
            ListNode nextHead = head.next;
            head.next = last;
            last = head;
            head = nextHead;
        }
        return last;
    }
}