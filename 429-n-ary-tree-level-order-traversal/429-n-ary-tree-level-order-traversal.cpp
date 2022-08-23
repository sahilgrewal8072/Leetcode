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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto node  = q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto it : node->children){
                    if(it != nullptr){
                        q.push(it);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};