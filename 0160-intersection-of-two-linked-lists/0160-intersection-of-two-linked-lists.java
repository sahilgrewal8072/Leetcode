/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int countA = 0;
        int countB = 0;
        ListNode it1 = headA;
        ListNode it2 = headB;
        while(it1 != null){
            countA++;
            it1 = it1.next;
        }
        while(it2 != null){
            countB++;
            it2 = it2.next;
        }
        it1 = headA;
        it2 = headB;
        if(countA > countB){
            for(int i = 0; i<(countA - countB); i++){
                it1 = it1.next;
            }
        }else{
            for(int i = 0; i<(countB - countA); i++){
                it2 = it2.next;
            }
        }
        
        while(it1 != null && it2 != null){
            if(it1 == it2)return it1;
            it1 = it1.next;
            it2 = it2.next;
        }
        return null;
    }
}