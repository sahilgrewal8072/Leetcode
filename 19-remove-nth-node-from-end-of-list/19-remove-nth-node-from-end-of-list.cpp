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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        prev->next = head;
        ListNode* nxt = head, *curr  = head;
        for(int i=0; i<n; i++){
            nxt = nxt->next;
        }
        // cout<<nxt->val<<" "<<endl;
        while(nxt){
            prev = curr;
            curr = curr->next;
            nxt = nxt->next;
        }
        
        prev->next = curr->next;
        // delete curr;
        return dummy->next;
    }
};