/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it == nullptr)s += ("#,");
            else{
                s += to_string(it->val) + ",";
                q.push(it->left);
                q.push(it->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return nullptr;
        }
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            getline(s, str, ',');
            
            if(str == "#"){
                it->left = nullptr;
            }else{
                TreeNode* lt = new TreeNode(stoi(str));
                it->left = lt;
                q.push(lt);
            }
            
            getline(s, str, ',');
            
            if(str == "#"){
                it->right = nullptr;
            }else{
                TreeNode* rt = new TreeNode(stoi(str));
                it->right = rt;
                q.push(rt);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));