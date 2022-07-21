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
    ListNode* solve(ListNode* tail, ListNode* curr){
        if(curr == nullptr){
            return tail;
        }
        ListNode *head = solve(curr, curr->next);
        curr->next = tail;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head;
        ListNode* tail = NULL;
        ListNode* curr = head;
     return solve(tail, curr);
    
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)return head;
        if(left == right)return head;
        ListNode* prev = NULL;
        ListNode* y = NULL;
        ListNode* z = NULL;
        ListNode* dummy = new ListNode(-1);
        prev = dummy;
        ListNode* x = dummy;
        ListNode* end = NULL;
        x->next = head;
        ListNode* it = head;
        int count = 1;
        while(it){
            if(count == left){
                x = prev;
                end = it;
            }else if(count == right){
                y = it;
                z = it->next;
            }
            if(++count > right){
                break;
            }
            prev = it;
            it = it->next;
        }
        y->next = NULL;
        x->next = solve(NULL, end);
        end->next = z;
        
        return dummy->next;
    }
};