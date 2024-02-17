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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int rem = 0;
        int sum = l1.val + l2.val;
        rem = sum%10;
        int carry = sum/10;
        ListNode prev = new ListNode(rem);
        ListNode ansHead = prev;
        l1 = l1.next;
        l2 = l2.next;
        while(l1 != null && l2 != null){
            sum = (l1.val + l2.val + carry);
            rem = (sum)%10;
            carry = sum/10;
            ListNode temp = new ListNode(rem);
            prev.next = temp;
            prev = temp;
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while(l1 != null){
            sum = l1.val + carry;
            rem = sum%10;
            carry = sum/10;
            ListNode temp = new ListNode(rem);
            prev.next = temp;
            prev = temp;
            l1 = l1.next;
        }
        
        while(l2 != null){
            sum = l2.val + carry;
            rem = sum%10;
            carry = sum/10;
            ListNode temp = new ListNode(rem);
             prev.next = temp;
            prev = temp;
            l2 = l2.next;
        }
        
        if(carry != 0){
            ListNode temp = new ListNode(carry);
             prev.next = temp;
            prev = temp;
        }
        return ansHead;
    }
}