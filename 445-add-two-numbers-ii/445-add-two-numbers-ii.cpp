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
        ListNode* it = l1;
        ListNode* pt = l2;
        int size1 = 0;
        int size2 = 0;
        while(it){
            size1++;
            it = it->next;
        }
        
        while(pt){
            size2++;
            pt = pt->next;
        }
        it = l1;
        pt = l2;
        ListNode* head = nullptr;
        while((size1 > 0 && size2 > 0) && (it && pt)){
            ListNode* temp = new ListNode(-111);
            if(size1 == size2){
                temp->val = it->val + pt->val;
                temp->next = head;
                head = temp;
                it = it->next;
                pt = pt->next;
                size1--;
                size2--;
            }else if(size1 > size2){
                temp->val = it->val;
                temp->next = head;
                head = temp;
                it = it->next;
                size1--;
            }else{
                temp->val = pt->val;
                temp->next = head;
                head = temp;
                pt = pt->next;
                size2--;
            }
            
        }
        
        ListNode* p = head;
        int carry = 0;
        int curr = (p->val);
        carry = curr/10;
        p->val = curr%10;
        head = head->next;
        p->next = nullptr;
        ListNode* dum = nullptr;
        while(head){
            curr = (head->val + carry);
            head->val = curr%10;
            carry = curr/10;
            dum = head->next;
            head->next = p;
            p = head;
            head = dum;
        }
        
        if(carry){
            ListNode* temp = new ListNode(carry);
            temp->next = p;
            p = temp;
        }
        
        return p;
    }
};