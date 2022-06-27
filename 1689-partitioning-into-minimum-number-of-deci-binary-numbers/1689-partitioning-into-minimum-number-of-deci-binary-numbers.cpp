class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int mx = 0;
        for(int i=0; i<len; i++){
            mx = max(mx, n[i] - '0');
        }
        return mx;
    }
};