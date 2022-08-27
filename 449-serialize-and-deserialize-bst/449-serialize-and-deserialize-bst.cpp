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
          queue<TreeNode*> q;
        if(!root)return "";
        string ans = "";
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it == NULL){ans.append("#,");}
            else{
                ans.append(to_string(it->val) + ',');
            }
            if(it != NULL){
                q.push(it->left);
                q.push(it->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){return NULL;}
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
                it->left = NULL;
            }else{
                TreeNode* curr = new TreeNode(stoi(str));
                it->left = curr;
                q.push(it->left);
            }
            getline(s, str, ',');
            if(str == "#"){
                it->right = NULL;
            }else{
                TreeNode* curr = new TreeNode(stoi(str));
                it->right = curr;
                q.push(it->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;