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
class MergeTwoLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        else if (l2 == null) return l1;

        ListNode protect = new ListNode(0, null);
        ListNode head = protect;

        while(l1 != null && l2 != null){
            if(l1.val > l2.val){
                protect.next = l2;
                protect = protect.next;
                l2 = l2.next;
            }else{
                protect.next = l1;
                protect = protect.next;
                l1 = l1.next;
            }
        }

        if (l2 != null) protect.next = l2;
        else if (l1 != null) protect.next = l1;
        return head.next;  
    }
}