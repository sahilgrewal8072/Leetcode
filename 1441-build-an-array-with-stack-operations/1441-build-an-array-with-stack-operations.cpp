class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=1;
        int it = 0;
        n = target[target.size()-1];
        while(i <= n){
            if(target[it] == i){
                it++;
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};