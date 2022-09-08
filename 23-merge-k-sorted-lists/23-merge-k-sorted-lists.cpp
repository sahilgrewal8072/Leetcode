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
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(!head1){
            return head2;
        }
        
        if(!head2){
            return head1;
        }
        
        ListNode* last = nullptr;
        if(head2->val  < head1->val){
            last = head2;
            last->next = merge(head1, head2->next);
        }else{
            last = head1;
            last->next = merge(head1->next, head2);
        }
        return last;
    }
    
    private:
    ListNode* merge_sort(vector<ListNode*> &lists, int start, int end){
        if(start > end){
            return nullptr;
        }
        
        if(start == end){
            return lists[start];
        }
        
        if(start + 1 == end){
            return merge(lists[start], lists[end]);
        }
        
        int mid = start + (end - start)/2;
        
        ListNode* left = merge_sort(lists, start, mid);
        ListNode* right = merge_sort(lists, mid + 1, end);
        return merge(left, right);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return merge_sort(lists, 0, n-1);
    }
};