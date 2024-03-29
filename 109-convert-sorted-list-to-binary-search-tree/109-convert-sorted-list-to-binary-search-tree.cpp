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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* solve(ListNode* head, ListNode* end){
        if(head == end)return nullptr;
        
        // finding the mid of the list;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != end && fast->next != end){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = solve(head, slow);
        root->right = solve(slow->next, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head, nullptr);
    }
};