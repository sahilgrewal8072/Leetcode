class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count++;
            count -= (bills[i] - 5)/5;
            if(count <= 0)return false;
        }
        return true;
    }
};