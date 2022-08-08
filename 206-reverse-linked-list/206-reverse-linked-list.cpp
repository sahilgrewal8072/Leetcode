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
    ListNode* reverseList(ListNode* curr, ListNode* prev){
        if(!curr)return prev;
        ListNode* head = reverseList(curr->next, curr);
        curr->next = prev;  
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        head = reverseList(head, nullptr);
        return head;
    }
};