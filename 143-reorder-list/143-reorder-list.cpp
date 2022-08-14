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
    private:
    ListNode* find_mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse_list(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode* mid = find_mid(head);
        ListNode* r = reverse_list(mid);
        ListNode* l = head->next;
        for(int i=0; l != r; i++, head = head->next){
            if(i&1){
                head->next = l;
                l = l->next;
            }else{
                head->next = r;
                r = r->next;
            }
        }
        
    }
};