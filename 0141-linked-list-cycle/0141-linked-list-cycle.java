/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null)return false;
        ListNode slow = head;
        ListNode fast = head;
        do{
            slow = slow.next;
            fast = fast.next;
            if(fast != null)fast = fast.next;
            if(slow != null && slow == fast)return true;
        }while((fast != null ) && fast != slow);
            return false;
    }
}