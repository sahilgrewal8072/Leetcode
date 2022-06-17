class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adj;
    
    
    void dfs(string &email, vector<string> &curr_acc){
        visited.insert(email);
        
        curr_acc.push_back(email);
        for(auto it : adj[email]){
            if(visited.find(it) == visited.end()){
                dfs(it, curr_acc);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        for(vector<string>& account : accountList){
            int accountSize = account.size();
            string firstEmail = account[1];
            for(int j=2; j<accountSize; j++){
                string email = account[j];
                adj[firstEmail].push_back(email);
                adj[email].push_back(firstEmail);
            }
        }
        
        
        vector<vector<string>> ans;
        for(vector<string> &account : accountList){
            string holder = account[0];
            string firstEmail = account[1];
            
            if(visited.find(firstEmail) == visited.end()){
                vector<string> curr_acc;
                curr_acc.push_back(holder);
                dfs(firstEmail, curr_acc);
                
                sort(curr_acc.begin() + 1, curr_acc.end());
                ans.push_back(curr_acc);
            }
        }
        return ans;
    }
};