/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* it1 = headA;
        ListNode* it2 = headB;
        int count1 = 0;
        int count2 = 0;
        
        while(it1){
            count1++;
            it1 = it1->next;
        }
        
        while(it2){
            count2++;
            it2 = it2->next;
        }
        it1 = headA;
        it2 = headB;
        if(count1 > count2){
            for(int i = 0; i < (count1 - count2); i++){
                it1 = it1->next;
            }
        }else{
            for(int i = 0; i < (count2 - count1); i++){
                it2 = it2->next;
            }
        }
        
        while(it1 && it2){
            if(it1 == it2)return it1;
            it1 = it1->next;
            it2 = it2->next;
        }
        
        return nullptr;
    }
};