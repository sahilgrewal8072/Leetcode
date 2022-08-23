/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private:
    void solve(Node* root, vector<int> &ans){
        if(!root)return;
        
        ans.push_back(root->val);
        for(auto it : root->children){
            solve(it, ans);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        // solve(root, ans);
        // return ans;
        if(!root)return {};
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            for(int i = node->children.size() - 1; i>=0; i--){
                if(node->children[i] != nullptr)
                st.push(node->children[i]);
            }
        }
        return ans;
    }
};