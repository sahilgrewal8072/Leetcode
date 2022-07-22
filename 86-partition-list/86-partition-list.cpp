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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode* head1  = new ListNode(-1);
        ListNode* before  = head1;
        ListNode* head2 = new ListNode(-1);
        ListNode* after = head2;
        while(head){
            if(head->val < x){
                before->next = head;
                before = head;
                head = head->next;
                before->next = NULL;
            }else{
                after->next = head;
                after = head;
                head = head->next;
                after->next = NULL;
            }
        }
        before->next = head2->next;
        return head1->next;
    }
};