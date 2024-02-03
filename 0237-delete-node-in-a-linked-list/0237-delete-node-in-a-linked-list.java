/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode nxt = node.next;
        int temp = node.val;
        node.val = nxt.val;
        nxt.val = temp;
        node.next = nxt.next;
        // delete nxt;
    }
}