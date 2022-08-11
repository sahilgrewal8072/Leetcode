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
    int find_len(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int len = find_len(head);
        int div = len/k;
        int p_div = len%k;
        ListNode* curr = head;
        int i = 0;
        ListNode* prev = nullptr;
        while(i < k){
            if(!curr)break;
             ListNode* newhead = curr;
            for(int i=0; i<div; i++){
                prev = curr;
                curr = curr->next;
            }
            
            if(p_div > 0){
                prev = curr;
                curr = curr->next;
                p_div--;
            }
            
            prev->next = nullptr;
            ans[i] = newhead;
            i++;
        }
        return ans;
    }
};