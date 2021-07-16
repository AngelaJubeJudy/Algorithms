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
class ReverseKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode protect = new ListNode(0, head);
        ListNode last = protect;

        // 分组：按组遍历
        while(head != null){
            // 保存每组的结束结点
            ListNode end = getEnd(head, k);
            // 指向下一组的那条边
            if(end == null) break;
            ListNode nextGroupHead = end.next;

            // 每组内部反转
            reverseList(head, end);

            // 指向上一组的那条边
            last.next = end;
            head.next = nextGroupHead;

            // 分组遍历：上一组的结尾和下一组的开头
            last = head;
            head = nextGroupHead;
        }
        return protect.next;
    }
    
    private ListNode getEnd(ListNode head, int k){
        while(head != null){
            k--;
            if (k == 0) break;
            head = head.next;
        }
        return head;
    }

    public void reverseList(ListNode head, ListNode end) {
        if(head == end) return;
        ListNode last = head;
        head = head.next;
        while(head != end){
            ListNode nextHead = head.next;
            head.next = last;  // 改一条边的指向
            last = head;
            head = nextHead;
        }
        end.next = last;
    }
}