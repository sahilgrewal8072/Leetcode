class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
    
        if(n == 1)return stones[0];
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }

        while(pq.size()  > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x != y){
                pq.push(y - x);
            }
        }
        if(pq.size() == 0)return 0;
        return pq.top();
    }
};