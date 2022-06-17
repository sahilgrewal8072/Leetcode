class DSU {
public:
    vector<int> representative;
    vector<int> size;
    
    DSU(int sz) : representative(sz), size(sz) {
        for (int i = 0; i < sz; ++i) {
            // Initially each group is its own representative
            representative[i] = i;
            // Intialize the size of all groups to 1
            size[i] = 1;
        }
    }
    
    // Finds the representative of group x
    int findRepresentative(int x) {
        if (x == representative[x]) {
            return x;
        }
        
        // This is path compression
        return representative[x] = findRepresentative(representative[x]);
    }
    
    // Unite the group that contains "a" with the group that contains "b"
    void unionBySize(int a, int b) {
        int representativeA = findRepresentative(a);
        int representativeB = findRepresentative(b);
        
        // If nodes a and b already belong to the same group, do nothing.
        if (representativeA == representativeB) {
            return;
        }
        
        // Union by size: point the representative of the smaller
        // group to the representative of the larger group.
        if (size[representativeA] >= size[representativeB]) {
            size[representativeA] += size[representativeB];
            representative[representativeB] = representativeA;
        } else {
            size[representativeB] += size[representativeA];
            representative[representativeA] = representativeB;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
                DSU dsu(accountListSize);

        unordered_map<string, int> emailGrp;
        for(int i=0; i<accountListSize; i++){
            int accountSize = accountList[i].size();
            for(int j=1; j<accountSize; j++){
                string email = accountList[i][j];
                string holder = accountList[i][0];
                if(emailGrp.find(email) == emailGrp.end()){
                    emailGrp[email] = i;
                }else{
                    dsu.unionBySize(i, emailGrp[email]);
                }
            }
        }
        
        unordered_map<int, vector<string>> components;
        for(auto emailIter : emailGrp){
            string email = emailIter.first;
            int grp = emailIter.second;
            components[dsu.findRepresentative(grp)].push_back(email);
        }
        
        vector<vector<string>> mergedAcc;
        for(auto componentIt : components){
            int grp = componentIt.first;
            vector<string> component = {accountList[grp][0]};
            component.insert(component.end(), componentIt.second.begin(), componentIt.second.end());
            sort(component.begin() + 1, component.end());
            mergedAcc.push_back(component);
        }
        return mergedAcc;
    }
};