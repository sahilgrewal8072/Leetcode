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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        ListNode* tail = nullptr;
        int length = 0;
        while(curr){
            tail = curr;
            curr = curr->next;
            length++;
        }
        tail->next = head;
        k = k%length;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }
        
        while(fast->next != head){
            slow = slow->next;
            fast = fast->next;
        }
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};