class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(encoded.size() + 1);
        int i;
        ans[0] = first;
        for(i=1; i<encoded.size()+1; i++){
            ans[i] = encoded[i-1] ^ ans[i-1];
        }
        return ans;
    }
};