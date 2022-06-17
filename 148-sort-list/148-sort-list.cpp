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
    
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* result = new ListNode(-1);
        ListNode* dummy = result;
        while(l1 && l2){
            if(l1->val <= l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        
        if(l1){
            dummy->next = l1;
           
        }
        
        if(l2){
            dummy->next = l2;
            
        }
        
        dummy = result;
        result = result->next;
        delete(dummy);
        return result;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        
        // find middle to break the list into two parts
        ListNode* temp = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return mergeList(left, right);
    }
};