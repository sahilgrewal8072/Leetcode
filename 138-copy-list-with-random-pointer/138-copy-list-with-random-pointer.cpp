/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            Node* nxt = curr->next;
            curr->next = temp;
            temp->next = nxt;
            curr = nxt;
        }
        
         curr = head;
        while(curr && curr->next){
            if(curr->random)
            curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        Node* newhead = new Node(-1);
        Node* p = newhead;
        p->next = head;
        Node* q = head;
        while(p && p->next){
            q = p->next->next;
            p->next->next = q->next;
            p->next = q;
            p = q;
        }
        return newhead->next;
    }
};