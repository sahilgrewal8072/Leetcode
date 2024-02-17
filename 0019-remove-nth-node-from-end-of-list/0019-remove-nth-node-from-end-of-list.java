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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = head;
        ListNode ahead = head;
        for(int i = 0; i<n; i++){
            ahead = ahead.next;
        }
        
        if(ahead == null)return head.next;
        while(ahead.next != null){
            prev = prev.next;
            ahead = ahead.next;
        }
        
        prev.next = prev.next.next;
        return head;
    }
}