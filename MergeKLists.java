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
class MergeKLists {
    public ListNode mergeKLists(ListNode[] lists) {
        return merge(lists, 0, lists.length - 1);
    }
    private ListNode merge(ListNode[] lists, int start, int end){
        if(start == end) return lists[start];
        if(start > end) return null;
        int mid = start + (end - start)/2;
        return mergeTwoLists(merge(lists, start, mid), merge(lists, mid+1, end));
    }

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