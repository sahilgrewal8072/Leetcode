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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode ahead = head;
        while(ahead != null){
            ListNode ahead_ahead = ahead.next;
            ahead.next = prev;
            prev = ahead;
            ahead = ahead_ahead;
        }
        return prev;
    }
}