class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }
        int k = 0;

        for(int i = 0; i < n; i++){
            if(mp.find(hand[i] - 1) == mp.end()){
                int x = hand[i];
                int count = 0;
                while(mp.find(x) != mp.end()){
                    count++;
                    mp[x]--;
                    if(mp[x] == 0){
                        mp.erase(x);
                    }
                    if(count == groupSize){
                        k++;
                        break;
                    }
                    x++;
                }
            }

        }
        return groupSize*k == n;
    }
};