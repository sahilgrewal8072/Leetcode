/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        int carry = 0;
        int curr = 0;
        while(l1  && l2){
            curr = (l1->val + l2->val) + carry;
            ListNode* t = new ListNode(curr%10);
            head->next = t;
            head = t;
            carry = curr/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            curr = (l1->val + carry);
            ListNode *t = new ListNode(curr%10);\
            head->next = t;
            head = t;
            carry = curr/10;
            l1 = l1->next;
        }
        
        while(l2){
            curr = (l2->val + carry);
            ListNode *t = new ListNode(curr%10);\
            head->next = t;
            head = t;
            carry = curr/10;
            l2 = l2->next;
        }
        
        if(carry){
            ListNode *t = new ListNode(carry);\
            head->next = t;
            head = t;
        }
        return dummy->next;
    }
};