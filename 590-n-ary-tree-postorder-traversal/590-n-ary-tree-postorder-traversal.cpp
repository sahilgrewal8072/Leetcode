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
    private:
    void solve(Node* root, vector<int> &ans){
        if(!root)return;
        for(auto it : root->children){
            solve(it, ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(!root)return {};
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            for(auto it : node->children){
                if(it != nullptr){
                    st.push(it);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};